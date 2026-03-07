#include "def/reg.hpp"
#include "def/optype.hpp"
#include "arch/InstStruct.hpp"
#include "arch/dcu/DCU.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "kit/MemAgent.hpp"
YABI_BEGIN

/**
 * 解码过程可概括为：DCU首先从QIP指向的当前内存地址上读取1字节，根据高位2bit判断该指令是无操作数指令还是有操作数指令，
 * 如果是有操作数指令，那么再继续读取1字节，解析寻址方式
 */

DCU::DCU(RegTableIO *rtb, MemoryIO *mem)
    : rtb_(rtb)
    , mem_(mem)
{

}

void DCU::decode(InstStruct *ins){
    try{
        readOpcode(ins);
        readAddrmod(ins);
    }
    catch(std::exception &e){
        throw YabiExcept(ERRDCU, e.what());
    }
}

memunit_t DCU::readMemunit(){
    MemAgent agent(rtb_, mem_);
    return agent.in(sizeof(memunit_t));
}

void DCU::readOpcode(InstStruct *ins){
    ubyte_t op = readMemunit();
    ins -> optype = (op & 0xC0) >> 6;   //获取操作码类型
    ins -> opcode = op;  //获取操作码
}

void DCU::readAddrmod(InstStruct *ins){
    if(ins -> optype == OPTYPE_TIDY) return;   //对于精简指令则不读取寻址字段

    ubyte_t mod = readMemunit();
    ins -> opsize = (mod & 0xC0) >> 6;  //获取操作数大小
    ins -> modsrc = (mod & 0x38) >> 3; //获取源操作数的寻址方式
    ins -> moddst = (mod & 0x07);         //获取目的操作数的寻址方式
}

YABI_END