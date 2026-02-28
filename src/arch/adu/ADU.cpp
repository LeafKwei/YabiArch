#include "arch/adu/ADU.hpp"
#include "def/op/opsize.hpp"
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
            return sizeof(byteunit_t);
        case OPSIZE_WORD:
            return sizeof(int16_t);
        case OPSIZE_DWOR:
            return sizeof(int32_t);
        default:
        case OPSIZE_QWOR:
            return sizeof(regunit_t);
    }
}

YABI_END
