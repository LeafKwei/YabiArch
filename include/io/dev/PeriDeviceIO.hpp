#ifndef YABI_PERIDEVICE_HPP
#define YABI_PERIDEVICE_HPP

#include "io/RandomIO.hpp"
YABI_BEGIN

class PeriDeviceIO : public RandomIO{
public:
    PeriDeviceIO();
    int ioid() const noexcept override;
	qword_t in(memaddr_t addr, iosize_t n) override;
    void out(memaddr_t addr, qword_t data, iosize_t n) override;

private:
 

private:
    
};

YABI_END
#endif