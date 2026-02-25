#ifndef YABI_TYPES_HPP
#define YABI_TYPES_HPP

#include <cstdint>
#include "def/yabi.hpp"
YABI_BEGIN

using regsize_t = int64_t;   //寄存器大小，亦即虚拟机支持的最大位宽
using memunit_t = int8_t; //内存单元大小
using charunit_t = int8_t;  //单字节大小
using errnum_t = int;        //错误码
using addr_t      = uint64_t; //地址
using iosize_t = uint8_t;    //UniIO数据大小
using opcode_t = unsigned char;  //操作码
using opcomb_t = uint8_t;   //操作数组合
using opsize_t = uint8_t;    //操作数大小

YABI_END
#endif