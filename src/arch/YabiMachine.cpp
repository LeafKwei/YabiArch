#include "utility/bit.hpp"
#include "def/io/reg.hpp"
#include "def/op/optype.hpp"
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
    alive_ = true;
    while(alive_){
        readOpcode();    //读取操作码类型和操作码到InstStruct
        readAddrmod(); //读取寻址方式到InstStruct
        setIO();  //读取操作数，然后设置对应的IO对象到InstStruct
    }
}

void YabiMachine::restart(){
    rtb_.bezero();
    rtb_.out(QIP, entry_, sizeof(regunit_t));
    start();
}

memunit_t YabiMachine::readMemunit(){
    regunit_t qip = rtb_.in(QIP, sizeof(regunit_t));
    memunit_t op = mem_.in(qip, sizeof(memunit_t));
    qip += sizeof(memunit_t);
    rtb_.out(QIP, qip, sizeof(regunit_t));   //更新QIP寄存器
}

void YabiMachine::readOpcode(){
    memunit_t op = readMemunit();
    ins_.optype = (op & 0xC0) >> 6;   //获取操作码类型
    ins_.opcode = (op & 0x3F);            //获取操作码
}

void YabiMachine::readAddrmod(){
    if(ins_.optype == OPTYPE_TIDY) return;   //对于精简指令则不读取寻址字段

    memunit_t mod = readMemunit();
    ins_.opsize = (mod & 0xC0) >> 6;  //获取操作数大小
    ins_.modsrc = (mod & 0x38) >> 3; //获取源操作数的寻址方式
    ins_.moddst = (mod & 0x07);         //获取目的操作数的寻址方式
}

void YabiMachine::setIO(){

}

InstFunc& YabiMachine::findInst(optype_t type, opcode_t code){

}

YABI_END