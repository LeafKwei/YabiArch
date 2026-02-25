#ifndef YABI_PERIDEVICE_HPP
#define YABI_PERIDEVICE_HPP

#include "io/UniIO.hpp"
YABI_BEGIN

class PeriDeviceIO : public UniIO{
public:
    PeriDeviceIO();
    int ioid() const noexcept override;
    errnum_t ioerr() const noexcept override;
    void cleanerr() noexcept override;
	regsize_t in(addr_t addr, iosize_t n) noexcept override;
    void out(addr_t addr, regsize_t data, iosize_t n) noexcept override;

private:
    errnum_t err_;

private:
    
};

YABI_END
#endif