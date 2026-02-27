#ifndef YABI_PERIDEVICE_HPP
#define YABI_PERIDEVICE_HPP

#include "io/RandIO.hpp"
YABI_BEGIN

class PeriDeviceIO : public RandIO{
public:
    PeriDeviceIO();
    int ioid() const noexcept override;
	regsize_t in(memaddr_t addr, iosize_t n) override;
    void out(memaddr_t addr, regsize_t data, iosize_t n) override;

private:
 

private:
    
};

YABI_END
#endif