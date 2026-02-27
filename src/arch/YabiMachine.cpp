#include "utility/bit.hpp"
#include "def/io/reg.hpp"
#include "def/eflag/eflag.hpp"
#include "arch/YabiMachine.hpp"
YABI_BEGIN

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
    /* 不存在停机标志时，持续取指令并运行 */
    while(!hasbit(rtb_.in(QEF, sizeof(regunit_t)), FLAG_SHUT)){
        
    }
}

void YabiMachine::restart(){
    rtb_.bezero();
    rtb_.out(QIP, entry_, sizeof(regunit_t));
    start();
}



YABI_END