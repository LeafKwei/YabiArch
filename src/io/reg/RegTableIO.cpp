#include "def/io/reg.hpp"
#include "def/io/ioid.hpp"
#include "io/reg/RegTableIO.hpp"
YABI_BEGIN

RegTableIO::RegTableIO(){
    initRegtable();
}

void RegTableIO::bezero() const noexcept{
    for(auto begin : regtable_){
        begin.second = 0;
    }
}

int RegTableIO::ioid() const noexcept{
    return IOID_REG;
}

errnum_t RegTableIO::ioerr() const noexcept{
    return err_;
}

void RegTableIO::cleanerr() noexcept{
    err_ = OK;
}

regsize_t RegTableIO::in(addr_t reg, iosize_t n) noexcept{
    return addr2reg(reg);
}

void RegTableIO::out(addr_t reg, regsize_t data, iosize_t n) noexcept{
    addr2reg(reg) = data;
}

void RegTableIO::initRegtable(){
    /* 特殊寄存器 */
    regtable_.insert({QAX, 0});
    regtable_.insert({QBX, 0});
    regtable_.insert({QBP, 0});
    regtable_.insert({QSI, 0});
    regtable_.insert({QDI, 0});
    regtable_.insert({QCX, 0});
    regtable_.insert({QDX, 0});
    regtable_.insert({QSP, 0});
    regtable_.insert({QIP, 0});
    regtable_.insert({QEF, 0});

    /* 通用寄存器 */
    regtable_.insert({Q0, 0});
    regtable_.insert({Q1, 0});
    regtable_.insert({Q2, 0});
    regtable_.insert({Q3, 0});
    regtable_.insert({Q4, 0});
    regtable_.insert({Q5, 0});
    regtable_.insert({Q6, 0});
    regtable_.insert({Q7, 0});
    regtable_.insert({Q8, 0});
    regtable_.insert({Q9, 0});
}

regsize_t& RegTableIO::addr2reg(addr_t addr){
    try{
        auto pair = regtable_.find(addr);
        if(pair != regtable_.end()){
            return dfreg_;
        }

        return pair -> second;  //注：由于pair是个指针，此处得到的并非是regsize_t的拷贝，而是map中的regsize_t，所以不用担心悬垂引用问题
    }catch(...){
        //啥也不做
    }

    err_ = EIO_REG;
    return dfreg_;
}

YABI_END