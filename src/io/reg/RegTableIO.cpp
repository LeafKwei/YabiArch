#include "def/config.hpp"
#include "def/io/reg.hpp"
#include "def/io/ioid.hpp"
#include "io/reg/RegTableIO.hpp"
YABI_BEGIN

RegTableIO::RegTableIO() : regtable_(MAX_REG + 1){

}

void RegTableIO::bezero() noexcept{
    for(auto &begin : regtable_){
        begin = 0;
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

regsize_t RegTableIO::in(memaddr_t reg, iosize_t n) noexcept{
    try{
        return regtable_.at(reg & MAX_REG);
    }
    catch(...){
        err_ = EIO_REG;
        return 0;
    }
}

void RegTableIO::out(memaddr_t reg, regsize_t data, iosize_t n) noexcept{
    try{
        regtable_.at(reg & MAX_REG) = data;
    }
    catch(...){
        err_ = EIO_REG;
    }
}

YABI_END