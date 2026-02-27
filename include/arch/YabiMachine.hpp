#ifndef YABI_MACHINE_HPP
#define YABI_MACHINE_HPP

#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "io/dev/PeriDeviceIO.hpp"
#include "arch/inst/InstStruct.hpp"
#include "addrmod/Addrmoder.hpp"
YABI_BEGIN

class YabiMachine{
public:
    void load(const char *program, memaddr_t addr);
    void setEntry(memaddr_t addr);
    void run();

private:
    InstStruct ins_;
    RegTableIO rtb_;
    MemoryIO mem_;
    PeriDeviceIO dev_;
    Addrmoder mod_;
};

YABI_END
#endif