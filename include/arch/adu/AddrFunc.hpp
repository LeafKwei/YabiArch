#ifndef YABIARCH_ADDRFUNC_HPP
#define YABIARCH_ADDRFUNC_HPP

#include <functional>
#include "def/types.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemAgent;
class OrderedIO;

/**
 * 寻址函数类型，每种寻址方式被实现为一个寻址函数 
 * rtb: 寄存器访问对象
 * agent: 内存访问对象(同步修改QIP)
 * size: 操作数长度
 * op: 操作数IO对象，寻址函数需要根据操作数的不同设置此IO对象的属性，以便后续流程能访问到操作数
 */
using AddrFunc = std::function<void(RegTableIO &rtb, MemAgent &agent, iosize_t size, OrderedIO *op)>;

YABI_END
#endif