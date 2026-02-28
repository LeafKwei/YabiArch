#ifndef YABIARCH_ADDRFUNC_HPP
#define YABIARCH_ADDRFUNC_HPP

#include <functional>
#include "def/types.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
class InstStruct;

/* 寻址函数类型，每种寻址方式被实现为一个寻址函数 */
using AddrFunc = std::function<iosize_t(RegTableIO *rtb, MemoryIO *mem, InstStruct *ins)>;

YABI_END
#endif