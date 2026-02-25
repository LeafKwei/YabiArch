#ifndef YABI_OPCODE_HPP
#define YABI_OPCODE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 指令操作码 //////////////////////////
/* Brainfuck 兼容指令*/
constexpr opcode_t OPCODE_MPLMV = 0x00; //内存指针左移
constexpr opcode_t OPCODE_MPRMV = 0x01; //内存指针右移
constexpr opcode_t OPCODE_MADD = 0x02;   //内存单元值+1
constexpr opcode_t OPCODE_MSUB = 0x03;   //内存单元值-1
constexpr opcode_t OPCODE_JIFZ = 0x04;       //如果内存单元为0则跳转
constexpr opcode_t OPCODE_JIFNZ = 0x05;    //如果内存单元不为0则跳转
constexpr opcode_t OPCODE_TERMIN = 0x06;   //从终端输入
constexpr opcode_t OPCODE_TERMOUT = 0x07; //输出到终端


YABI_END
#endif