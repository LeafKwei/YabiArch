#include "def/config.hpp"
#include "def/opcode.hpp"
#include "def/optype.hpp"
#include "arch/ixu/IXU.hpp"
#include "arch/ixu/instfuncs.hpp"
YABI_BEGIN

IXU::IXU(RegTableIO *rtb, MemoryIO *mem, PeriDeviceIO *dev)
    : rtb_(rtb)
    , mem_(mem)
    , dev_(dev)
    , inst_(MAX_INST + 1)
{
    registerTidyInstructions();
    registerOrdiInstructions();
    registerCompInstructions();
}

void IXU::execute(InstStruct *ins){
    /* 使用指令编码作为索引从指令集中找到对应的指令并调用 */
    try{
        inst_.at(ins -> opcode)(rtb_, mem_, dev_, ins);
    }
    catch(YabiExcept ye){
        throw;
    }
    catch(std::exception e){
        throw YabiExcept(ERROPCODE, e.what());
    }
}

void IXU::registerTidyInstructions(){
    inst_.at(OPCODE_SHUT) = inst_tidy_shut;
    inst_.at(OPCODE_DBG) = inst_tidy_dbg;
}

void IXU::registerOrdiInstructions(){
    inst_.at(OPCODE_JMP) = inst_ordi_jmp;
    inst_.at(OPCODE_JMPE) = inst_ordi_jmpe;
}

void IXU::registerCompInstructions(){
    inst_.at(OPCODE_MOV) = inst_comp_mov;
    inst_.at(OPCODE_ADD) = inst_comp_add;
    inst_.at(OPCODE_SUB) = inst_comp_sub;
    inst_.at(OPCODE_CMP) = inst_comp_cmp;
    inst_.at(OPCODE_IN) = inst_comp_in;
    inst_.at(OPCODE_OUT) = inst_comp_out;
}

YABI_END