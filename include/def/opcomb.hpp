#ifndef YABI_OPCOMB_HPP
#define YABI_OPCOMB_HPP

#include "def/types.hpp"
YABI_BEGIN

//YabiArch的指令操作数按(源操作数, 目的操作数)的顺序给出
constexpr opcomb_t OPCOMB_NA = 0x00;   //无操作数
constexpr opcomb_t OPCOMB_IMM = 0x01; //立即数
constexpr opcomb_t OPCOMB_REG = 0x02; //寄存器
constexpr opcomb_t OPCOMB_IR = 0x03; //(立即数，寄存器)
constexpr opcomb_t OPCOMB_RR = 0x04; //(寄存器，寄存器)
constexpr opcomb_t OPCOMB_MR = 0x05; //(内存，寄存器)
constexpr opcomb_t OPCOMB_RM =0x06;  //(寄存器，内存)

YABI_END
#endif