#include "def/opcode.hpp"
#include "def/optype.hpp"
#include "arch/ixu/IXU.hpp"
#include "arch/ixu/instfuncs.hpp"
YABI_BEGIN

IXU::IXU(RegTableIO *rtb, MemoryIO *mem, PeriDeviceIO *dev)
    : rtb_(rtb)
    , mem_(mem)
    , dev_(dev)
{
    registerTidyInstructions();
    registerOrdiInstructions();
    registerCompInstructions();
}

void IXU::execute(InstStruct *ins){
    /* 根据指令类型选择不同指令集并交给executeFor函数搜索对应的指令执行 */
    switch(ins -> optype){
        case OPTYPE_TIDY:
            executeFor(tidyinst_, ins);
            return;
        case OPTYPE_ORDI:
            executeFor(ordinst_, ins);
            return;
            executeFor(compinst_, ins);
        case OPTYPE_COMP:
            return;
    }
}

void IXU::executeFor(std::unordered_map<opcode_t, InstFunc> &insts, InstStruct *ins){
    auto pair = insts.find(ins -> opcode);
    if(pair == insts.end()){
        throw YabiExcept(EOPCODE);
    }

    pair -> second(rtb_, mem_, dev_, ins);
}

void IXU::registerTidyInstructions(){
    tidyinst_.insert({OPCODE_SHUT, inst_tidy_shut});
    tidyinst_.insert({OPCODE_DBG, inst_tidy_dbg});
}

void IXU::registerOrdiInstructions(){
    ordinst_.insert({OPCODE_JMP, inst_ordi_jmp});
    ordinst_.insert({OPCODE_JMPE, inst_ordi_jmpe});
}

void IXU::registerCompInstructions(){
    compinst_.insert({OPCODE_MOV, inst_comp_mov});
    compinst_.insert({OPCODE_ADD, inst_comp_add});
    compinst_.insert({OPCODE_SUB, inst_comp_sub});
    compinst_.insert({OPCODE_CMP, inst_comp_cmp});
    compinst_.insert({OPCODE_IN, inst_comp_in});
    compinst_.insert({OPCODE_OUT, inst_comp_out});
    
}

YABI_END