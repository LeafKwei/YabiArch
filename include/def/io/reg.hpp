#ifndef YABI_REG_HPP
#define YABI_REG_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////!!!! 寄存器由于编码限制位6bit仅允许定义最多64个，且由于于寻址寄存器由于只使用2bit编码，因此必须定义在最前方 !!!!/////////////////////
////////////////////////// 特殊寄存器 //////////////////////////
/* 寻址专用寄存器 */
constexpr memaddr_t QBX = 0b00; //基址寄存器
constexpr memaddr_t QBP = 0b01;  //基指针寄存器
constexpr memaddr_t QSI = 0b10;  //源地址寄存器
constexpr memaddr_t QDI = 0b11; //目的地址寄存器

/* 其他特殊寄存器 */
constexpr memaddr_t QAX = 0x04;
constexpr memaddr_t QCX = 0x05; //条件/计数寄存器
constexpr memaddr_t QDX = 0x06;
constexpr memaddr_t QSP = 0x07;  //栈指针寄存器
constexpr memaddr_t QIP = 0x08;   //指令指针寄存器
constexpr memaddr_t QEF = 0x09;  //标志寄存器

////////////////////////// 通用寄存器 //////////////////////////
constexpr memaddr_t Q0 = 0x0a;
constexpr memaddr_t Q1 = 0x0b;
constexpr memaddr_t Q2 = 0x0c;
constexpr memaddr_t Q3 = 0x0d;
constexpr memaddr_t Q4 = 0x0e;
constexpr memaddr_t Q5 = 0x0f;
constexpr memaddr_t Q6 = 0x10;
constexpr memaddr_t Q7 = 0x11;
constexpr memaddr_t Q8 = 0x12;
constexpr memaddr_t Q9 = 0x13;

YABI_END
#endif