#ifndef YABI_CONFIG_HPP
#define YABI_CONFIG_HPP

#include "def/yabi.hpp"
YABI_BEGIN

constexpr int MAX_REG = 0x3F;               //最大寄存器编号
constexpr int MEM_INIT_SIZE = 0xFFFF;  //初始内存大小为64KB
constexpr int MEM_RESZ_SIZE = 0xFFFF;  //重新扩容时，在满足最低需求的情况下额外扩充的内存
constexpr int PORT_ALLOC_SIZE = 32;  //单次端口分配数量

YABI_END
#endif