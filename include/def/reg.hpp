#ifndef YABI_REG_HPP
#define YABI_REG_HPP

#include "def/yabi.hpp"
YABI_BEGIN

////////////////////////// 特殊寄存器 //////////////////////////
constexpr addr_t QAX = 0;
constexpr addr_t QBX = 1; //基址寄存器
constexpr addr_t QCX = 2; //条件/计数寄存器
constexpr addr_t QDX = 3;
constexpr addr_t QMP = 10; //内存指针寄存器(指向当前操作的内存单元，用于兼容BF)
constexpr addr_t QBP = 11;  //基指针寄存器
constexpr addr_t QSP = 12;  //栈指针寄存器
constexpr addr_t QIP = 13;   //指令指针寄存器
constexpr addr_t QSI = 14;  //源地址寄存器
constexpr addr_t QDI = 15; //目的地址寄存器
constexpr addr_t QEF = 25;  //标志寄存器

////////////////////////// 通用寄存器 //////////////////////////
constexpr addr_t Q0 = 30;
constexpr addr_t Q1 = 31;
constexpr addr_t Q2 = 32;
constexpr addr_t Q3 = 33;
constexpr addr_t Q4 = 34;
constexpr addr_t Q5 = 35;
constexpr addr_t Q6 = 36;
constexpr addr_t Q7 = 37;
constexpr addr_t Q8 = 38;
constexpr addr_t Q9 = 39;

YABI_END
#endif