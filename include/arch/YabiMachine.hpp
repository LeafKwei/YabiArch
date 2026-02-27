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
    YabiMachine() =default;
    void load(const byteunit_t *program, seqsize_t n, memaddr_t addr);
    void setEntry(memaddr_t addr);
    void start();
    void restart();

private:
    memaddr_t entry_;
    InstStruct ins_;
    RegTableIO rtb_;
    MemoryIO mem_;
    PeriDeviceIO dev_;
    Addrmoder mod_;

private:

};

YABI_END
#endif