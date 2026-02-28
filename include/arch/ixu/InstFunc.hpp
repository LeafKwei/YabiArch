#ifndef YABIARCH_INSTFUNC_HPP
#define YABIARCH_INSTFUNC_HPP

#include <functional>
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
class PeriDeviceIO;
class InstStruct;

/* 指令函数类型，每种指令被实现为一个指令函数 */
using InstFunc = std::function<void(RegTableIO *rtb, MemoryIO *mem, PeriDeviceIO *dev, InstStruct *ins)>;

YABI_END
#endif