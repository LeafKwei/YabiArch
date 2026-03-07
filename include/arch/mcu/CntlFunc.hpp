#ifndef YABI_CNTLFUNC_HPP
#define YABI_CNTLFUNC_HPP

#include <functional>
#include "def/yabi.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
struct MachineInf;
struct InstStruct;

/**
 * 控制函数类型，每种控制操作被实现为一个函数
 * rtb: 寄存器访问对象
 * mem: 内存访问对象
 * inf: 机器信息结构对象
 * ins: 指令结构对象
 */
using CntlFunc = std::function<void(RegTableIO &rtb, MemoryIO &mem, MachineInf &inf, InstStruct &ins)>;

YABI_END
#endif