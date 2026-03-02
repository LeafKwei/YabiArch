#include "utility/bit.hpp"
#include "def/reg.hpp"
#include "def/optype.hpp"
#include "def/eflag.hpp"
#include "arch/YabiMachine.hpp"
YABI_BEGIN

YabiMachine::YabiMachine()
    : dcu_(&rtb_, &mem_)
    , adu_(&rtb_, &mem_)
    , pcu_(&rtb_, &mem_)
    , ixu_(&rtb_, &mem_, &dev_)
    , mcu_(&rtb_, &mem_)
{

}

void YabiMachine::load(const byte_t *program, seqsize_t n ,memaddr_t addr){
    for(seqsize_t idx = 0; idx < n; idx++){
        mem_.out(addr + idx, program[idx], sizeof(byte_t));
    }
}

void YabiMachine::setEntry(memaddr_t addr){
    entry_ = addr;
    rtb_.out(QIP, addr, sizeof(qword_t));
}

void YabiMachine::start(){
    inf_.alive = true;
    while(inf_.alive){
        dcu_.decode(&ins_);
        pcu_.precheck(&ins_);
        adu_.addressing(&ins_);
        ixu_.execute(&ins_);
        mcu_.control(&inf_);
    }
}

void YabiMachine::restart(){
    rtb_.bezero();
    rtb_.out(QIP, entry_, sizeof(qword_t));
    start();
}

YABI_END