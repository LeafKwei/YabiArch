#include "def/config.hpp"
#include "def/opcode.hpp"
#include "def/optype.hpp"
#include "arch/ixu/IXU.hpp"
#include "arch/ixu/instfuncs.hpp"
YABI_BEGIN

/**
 * 指令执行过程可概括为：IXU根据指令编码opcode找到对应的指令函数，然后使用适当的参数调用该函数即可
 */

IXU::IXU(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev)
    : rtb_(rtb)
    , mem_(mem)
    , dev_(dev)
    , inst_(MAX_INST + 1)
{
    registerNOPInstructions();
    registerSOPInstructions();
    registerDOPInstructions();
}

void IXU::execute(InstStruct &ins){
    /* 使用指令编码作为索引从指令集中找到对应的指令并调用 */
    try{
        inst_.at(ins.opcode)(rtb_, mem_, dev_, ins);
    }
    catch(std::exception &e){
        throw YabiExcept(ERRIXU, e.what());
    }
}

void IXU::registerNOPInstructions(){
    inst_.at(OPCODE_SHUT) = inst_nop_shut;
    inst_.at(OPCODE_DBG) = inst_nop_dbg;
}

void IXU::registerSOPInstructions(){
    inst_.at(OPCODE_JMP) = inst_sop_jmp;
    inst_.at(OPCODE_JMPE) = inst_sop_jmpe;
}

void IXU::registerDOPInstructions(){
    inst_.at(OPCODE_MOV) = inst_dop_mov;
    inst_.at(OPCODE_ADD) = inst_dop_add;
    inst_.at(OPCODE_SUB) = inst_dop_sub;
    inst_.at(OPCODE_CMP) = inst_dop_cmp;
    inst_.at(OPCODE_IN) = inst_dop_in;
    inst_.at(OPCODE_OUT) = inst_dop_out;
}

YABI_END