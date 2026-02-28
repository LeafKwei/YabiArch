#include "io/op/RegopIO.hpp"
#include "io/reg/RegTableIO.hpp"
YABI_BEGIN

void RegopIO::setReg(RegTableIO *rtb, memaddr_t reg, iosize_t size){
    rtb_ = rtb;
    reg_ = reg;
    size_ = size;
}

int RegopIO::ioid() const noexcept{

}

memaddr_t RegopIO::addr() const noexcept{
    return reg_;
}

iosize_t RegopIO::size() const noexcept{
    return size_;
}

void RegopIO::moveup() noexcept{
    //此操作无效
}

void RegopIO::movedown() noexcept{
    //此操作无效
}

qword_t RegopIO::in(){
    return rtb_ -> in(reg_, size_);
}

void RegopIO::out(qword_t data){
    rtb_ -> out(reg_, data, size_);
}


YABI_END