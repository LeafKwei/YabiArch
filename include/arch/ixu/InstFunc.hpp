#ifndef YABIARCH_INSTFUNC_HPP
#define YABIARCH_INSTFUNC_HPP

#include "def/yabi.hpp"
#include <functional>
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
class PeriDeviceIO;
struct InstStruct;

/** 
 * 指令函数类型，每种指令被实现为一个指令函数 
 * rtb: 寄存器访问对象
 * mem: 内存访问对象
 * dev: 外部设备访问对象
 * ins: 指令结构对象
 */
using InstFunc = std::function<void(RegTableIO *rtb, MemoryIO *mem, PeriDeviceIO *dev, InstStruct *ins)>;

YABI_END
#endif