#include "def/port.hpp"
#include "def/ioid.hpp"
#include "io/dev/PeriDeviceIO.hpp"
YABI_BEGIN

PeriDeviceIO::PeriDeviceIO(){

}

int PeriDeviceIO::ioid() const noexcept{
    return IOID_DEV;
}

qword_t PeriDeviceIO::in(memaddr_t addr, iosize_t n){
    return 65;
}

void PeriDeviceIO::out(memaddr_t addr, qword_t data, iosize_t n){

}



YABI_END