#ifndef YABI_MACHINE_HPP
#define YABI_MACHINE_HPP

#include <unordered_map>
#include "arch/dcu/DCU.hpp"
#include "arch/adu/ADU.hpp"
#include "arch/ixu/IXU.hpp"
#include "arch/InstStruct.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "io/dev/PeriDeviceIO.hpp"
YABI_BEGIN

class YabiMachine{
public:
    YabiMachine();
    void load(const byte_t *program, seqsize_t n, memaddr_t addr);
    void setEntry(memaddr_t addr);
    void start();
    void restart();

private:
    bool alive_;
    memaddr_t entry_;
    InstStruct ins_;

    /* 设备 */
    RegTableIO rtb_;
    MemoryIO mem_;
    PeriDeviceIO dev_;
    
    /* 核心组件 */
    DCU dcu_;
    ADU adu_;
    IXU   ixu_;

private:

};

YABI_END
#endif