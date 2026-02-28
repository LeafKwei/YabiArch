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

regunit_t RegTableIO::in(memaddr_t reg, iosize_t n) noexcept{
    try{
        return regtable_.at(reg & MAX_REG);
    }
    catch(std::exception e){
        throw YabiExcept(EIOREG, e.what());
    }
}

void RegTableIO::out(memaddr_t reg, regunit_t data, iosize_t n) noexcept{
    try{
        regtable_.at(reg & MAX_REG) = data;
    }
    catch(std::exception e){
        throw YabiExcept(EIOREG, e.what());
    }
}

YABI_END