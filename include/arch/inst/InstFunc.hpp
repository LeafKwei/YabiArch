#ifndef YABIARCH_INSTFUNC_HPP
#define YABIARCH_INSTFUNC_HPP

#include <functional>
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "io/dev/PeriDeviceIO.hpp"
#include "inst/InstStruct.hpp"
YABI_BEGIN

/* 实现opcode对应的指令功能，每条指令允许访问寄存器、内存、设备、自身的指令结构体 */
using InstFunc = std::function<void(RegTableIO *rtb, MemoryIO *mem, PeriDeviceIO *dev, InstStruct *ins)>;

YABI_END
#endif