#ifndef YABI_REG_HPP
#define YABI_REG_HPP

#include "def/yabi.hpp"
YABI_BEGIN

////////////////////////// 特殊寄存器 //////////////////////////
constexpr int QAX = 0;
constexpr int QBX = 1; //基址寄存器
constexpr int QCX = 2; //条件/计数寄存器
constexpr int QDX = 3;
constexpr int QMP = 10; //内存指针寄存器(指向当前操作的内存单元，用于兼容BF)
constexpr int QBP = 11;  //基指针寄存器
constexpr int QSP = 12;  //栈指针寄存器
constexpr int QIP = 13;   //指令指针寄存器
constexpr int QSI = 14;  //源地址寄存器
constexpr int QDI = 15; //目的地址寄存器
constexpr int QEF = 25;  //标志寄存器

////////////////////////// 通用寄存器 //////////////////////////
constexpr int Q0 = 30;
constexpr int Q1 = 31;
constexpr int Q2 = 32;
constexpr int Q3 = 33;
constexpr int Q4 = 34;
constexpr int Q5 = 35;
constexpr int Q6 = 36;
constexpr int Q7 = 37;
constexpr int Q8 = 38;
constexpr int Q9 = 39;

YABI_END
#endif