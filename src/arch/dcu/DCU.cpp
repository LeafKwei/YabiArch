#include "def/reg.hpp"
#include "def/optype.hpp"
#include "arch/InstStruct.hpp"
#include "arch/dcu/DCU.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "kit/MemAgent.hpp"
YABI_BEGIN

DCU::DCU(RegTableIO *rtb, MemoryIO *mem)
    : rtb_(rtb)
    , mem_(mem)
{

}

void DCU::decode(InstStruct *ins){
    readOpcode(ins);
    readAddrmod(ins);
}

memunit_t DCU::readMemunit(){
    MemAgent agent(rtb_, mem_);
    return agent.in(sizeof(memunit_t));
}

void DCU::readOpcode(InstStruct *ins){
    memunit_t op = readMemunit();
    ins -> optype = (op & 0xC0) >> 6;   //获取操作码类型
    ins -> opcode = (op & 0x3F);            //获取操作码
}

void DCU::readAddrmod(InstStruct *ins){
    if(ins -> optype == OPTYPE_TIDY) return;   //对于精简指令则不读取寻址字段

    memunit_t mod = readMemunit();
    ins -> opsize = (mod & 0xC0) >> 6;  //获取操作数大小
    ins -> modsrc = (mod & 0x38) >> 3; //获取源操作数的寻址方式
    ins -> moddst = (mod & 0x07);         //获取目的操作数的寻址方式
}

YABI_END