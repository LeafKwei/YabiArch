#include "def/io/ioid.hpp"
#include "io/op/ImmopIO.hpp"
YABI_BEGIN

ImmopIO::ImmopIO(regunit_t imm, iosize_t size)
    : imm_(imm)
    , size_(size)
{

}

int ImmopIO::ioid() const noexcept{
    return IOID_IMMOP;
}

memaddr_t ImmopIO::addr() const noexcept{
    //此操作无效
    return 0;
}

iosize_t ImmopIO::size() const noexcept{
    return size_;
}

void ImmopIO::moveup() noexcept{
     //此操作无效
}

void ImmopIO::movedown() noexcept{
    //此操作无效
}   

regunit_t ImmopIO::in(){
    return imm_;
}   

void ImmopIO::out(regunit_t data){
    //此操作无效
}

YABI_END