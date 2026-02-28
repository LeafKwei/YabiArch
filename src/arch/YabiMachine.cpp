#include "utility/bit.hpp"
#include "def/io/reg.hpp"
#include "def/op/optype.hpp"
#include "def/eflag/eflag.hpp"
#include "arch/YabiMachine.hpp"
YABI_BEGIN

YabiMachine::YabiMachine()
    : dcu_(&rtb_, &mem_)
    , adu_(&rtb_, &mem_)
    , ixu_(&rtb_, &mem_, &dev_)
{

}

void YabiMachine::load(const byteunit_t *program, seqsize_t n ,memaddr_t addr){
    for(seqsize_t idx = 0; idx < n; idx++){
        mem_.out(addr + idx, program[idx], sizeof(byteunit_t));
    }
}

void YabiMachine::setEntry(memaddr_t addr){
    entry_ = addr;
    rtb_.out(QIP, addr, sizeof(regunit_t));
}

void YabiMachine::start(){
    alive_ = true;
    while(alive_){
        dcu_.decode(&ins_);
        adu_.addressing(&ins_);
        ixu_.execute(&ins_);
    }
}

void YabiMachine::restart(){
    rtb_.bezero();
    rtb_.out(QIP, entry_, sizeof(regunit_t));
    start();
}

YABI_END