#include "arch/adu/ADU.hpp"
#include "def/err.hpp"
#include "def/opsize.hpp"
#include "def/optype.hpp"
#include "def/addrmod.hpp"
#include "arch/InstStruct.hpp"
#include "arch/adu/IMMAddr.hpp"
#include "arch/adu/REGAddr.hpp"
#include "arch/adu/DIRAddr.hpp"
#include "arch/adu/INDAddr.hpp"
#include "arch/adu/BASAddr.hpp"
#include "arch/adu/IDXAddr.hpp"
#include "arch/adu/BXIAddr.hpp"
#include "arch/adu/SCAAddr.hpp"
YABI_BEGIN

ADU::ADU(RegTableIO *rtb, MemoryIO *mem){
    /* 分别为源操作数和目的操作数各注册一套寻址对象，避免当两个操作数寻址方式相同时导致寻址对象被共用而出现冲突 */
    registerAddrFunc(addrsrc_);
    registerAddrFunc(addrdst_);
}

void ADU::addressing(InstStruct *ins){
    switch(ins -> optype){
        case OPTYPE_TIDY:    //精简指令不进行寻址
            return;
        case OPTYPE_COMP: //复杂指令对两个操作数寻址(利用fall-through完成dst的寻址)
            addressingFor(addrsrc_, ins -> modsrc, opsize2iosize(ins -> opsize), &(ins -> src));
        case OPTYPE_ORDI:   //简单指令只对目的操作数寻址
            addressingFor(addrdst_, ins -> moddst, opsize2iosize(ins -> opsize), &(ins -> dst));
            return;
    }
}

void ADU::addressingFor(std::unordered_map<addrmod_t, AddrFunc> &funcs, addrmod_t mod, iosize_t opsize, OrderedIO **op){
    auto pair = funcs.find(mod);
    if(pair == funcs.end()) throw YabiExcept(EADMOD);

    MemAgent agent(rtb_, mem_);
    pair -> second(rtb_, &agent, opsize, op);
}

void ADU::registerAddrFunc(std::unordered_map<addrmod_t, AddrFunc> &funcs){
    funcs.insert({ADDRMOD_IMM, IMMAddr()});
    funcs.insert({ADDRMOD_REG, REGAddr()}); 
    funcs.insert({ADDRMOD_M_DIR, DIRAddr()}); 
    funcs.insert({ADDRMOD_M_IND, INDAddr()}); 
    funcs.insert({ADDRMOD_M_BAS, BASAddr()});
    funcs.insert({ADDRMOD_M_IDX, IDXAddr()});
    funcs.insert({ADDRMOD_M_BXI, BXIAddr()});
    funcs.insert({ADDRMOD_M_SCA, SCAAddr()});
}

iosize_t ADU::opsize2iosize(opsize_t opsize){
    switch(opsize){
        case OPSIZE_BYTE:
            return sizeof(byte_t);
        case OPSIZE_WORD:
            return sizeof(word_t);
        case OPSIZE_DWOR:
            return sizeof(dword_t);
        default:
        case OPSIZE_QWOR:
            return sizeof(qword_t);
    }
}

YABI_END
