#include "def/err.hpp"
#include "def/opsize.hpp"
#include "def/optype.hpp"
#include "def/addrmod.hpp"
#include "arch/adu/ADU.hpp"
#include "arch/adu/addrfuncs.hpp"
#include "arch/zeta/InstStruct.hpp"
YABI_BEGIN

/**
 * 寻址过程可概括为：根据源操作数或目的操作数的不同从不同的IOBundle中获取与寻址方式匹配的IO对象地址，
 * 然后由寻址函数对操作数进行寻址，将寻址结构设置到IO对象中，而后指令执行时就可直接通过IO对象获取到
 * 操作数，无需关心操作数的来源
 */

ADU::ADU(RegTableIO &rtb, MemoryIO &mem)
    : rtb_(rtb)
    , mem_(mem)
{
    registerAddrFuncs();
}

void ADU::addressing(InstStruct &ins){
    try{
        switch(ins. optype){
            case OPTYPE_NOP:  //无操作数指令不进行寻址
                return;
            case OPTYPE_SOP:   //单操作数指令只对目的操作数寻址
                addressingDST(ins);
                return;
            case OPTYPE_DOP: //双操作数指令对两个操作数寻址
                addressingSRC(ins);
                addressingDST(ins);
                return;
        }
    }
    catch(std::exception &e){
        throw YabiExcept(ERRADU, e.what());
    }
}

void ADU::addressingSRC(InstStruct &ins){
    OrderedIO *op = selectIO(srcbundle_, ins. modsrc);
    ins. src = op;
    addressingOn(ins. modsrc, opsize2iosize(ins. opsize), ins. src);
}

void ADU::addressingDST(InstStruct &ins){
    OrderedIO *op = selectIO(dstbundle_, ins. moddst);
    ins. dst = op;
    addressingOn(ins. modsrc, opsize2iosize(ins. opsize), ins. dst);
}

void ADU::addressingOn(addrmod_t mod, iosize_t size, OrderedIO *op){
    /* 如果没有对应的寻址函数，则抛出异常 */
    auto pair = addrfuncs_.find(mod);
    if(pair == addrfuncs_.end()) throw YabiExcept(ERRADMOD, "Unsupported addrmod.");

    /* 调用寻址函数寻址并设置操作数的IO对象 */
    MemAgent agent(rtb_, mem_);
    pair -> second(rtb_, agent, size, op);
}

OrderedIO* ADU::selectIO(IOBundle &bundle, addrmod_t mod){
    /* 根据寻址方式的不同返回相应的IO对象地址 */
    switch(mod){
        case ADDRMOD_IMM:
            return &(bundle.immop);
        case ADDRMOD_REG:
            return &(bundle.regop);
        default:
            return &(bundle.memop);
    }
}

void ADU::registerAddrFuncs(){
    addrfuncs_.insert({ADDRMOD_IMM, addr_IMM});
    addrfuncs_.insert({ADDRMOD_REG, addr_REG}); 
    addrfuncs_.insert({ADDRMOD_M_DIR, addr_DIR}); 
    addrfuncs_.insert({ADDRMOD_M_IND, addr_IND}); 
    addrfuncs_.insert({ADDRMOD_M_BAS, addr_BAS});
    addrfuncs_.insert({ADDRMOD_M_IDX, addr_IDX});
    addrfuncs_.insert({ADDRMOD_M_BXI, addr_BXI});
    addrfuncs_.insert({ADDRMOD_M_SCA, addr_SCA});
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
