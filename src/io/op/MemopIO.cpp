#include "def/io/ioid.hpp"
#include "io/op/MemopIO.hpp"
#include "io/mem/MemoryIO.hpp"
YABI_BEGIN

MemopIO::MemopIO(MemoryIO *mem, memaddr_t addr, iosize_t size)
    : mem_(mem)
    , addr_(addr)
    , size_(size)
{

}

int MemopIO::ioid() const noexcept{
    return IOID_MEMOP;
}   

memaddr_t MemopIO::addr() const noexcept{
    return addr_;
}

iosize_t MemopIO::size() const noexcept{
    return size_;
}

void MemopIO::moveup() noexcept{
    addr_ += size_;
}   

void MemopIO::movedown() noexcept{
    addr_ -= size_;
}

regunit_t MemopIO::in(){
    return mem_ -> in(addr_, size_);
}

void MemopIO::out(regunit_t data){
    mem_ -> out(addr_, data, size_);
}

YABI_END