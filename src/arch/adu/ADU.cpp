#include "arch/adu/ADU.hpp"
#include "def/opsize.hpp"
YABI_BEGIN

ADU::ADU(RegTableIO *rtb, MemoryIO *mem){

}

void ADU::addressing(InstStruct *ins){

}

void ADU::registerAddrFuncs(){

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
