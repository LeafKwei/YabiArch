#ifndef YABI_IOID_HPP
#define YABI_IOID_HPP

#include "def/yabi.hpp"
YABI_BEGIN

////////////////////////// IO id用于标识IO对象的用途 //////////////////////////
constexpr int IOID_REG = 0;   //寄存器IO
constexpr int IOID_MEM = 1; //内存IO
constexpr int IOID_DEV = 2;  //设备IO
constexpr int IOID_IMMOP = 3; //立即数操作数IO
constexpr int IOID_REGOP = 4;    //寄存器操作数IO
constexpr int IOID_MEMOP = 5;  //内存操作数IO

YABI_END

#endif