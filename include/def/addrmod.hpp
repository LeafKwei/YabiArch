#ifndef YABI_ADDRMOD_HPP
#define YABI_ADDRMOD_HPP

#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 寻址方式 //////////////////////////
constexpr addrmod_t ADDRMOD_IMM = 0b000;  //立即数寻址 jmp 1000h
constexpr addrmod_t ADDRMOD_REG = 0b001;   //寄存器寻址 jmp qax

/* 存储器寻址 */
constexpr addrmod_t ADDRMOD_M_DIR = 0b010; //直接寻址 jmp [1000h]
constexpr addrmod_t ADDRMOD_M_IND = 0b011; //间接寻址 jmp [qbx]
constexpr addrmod_t ADDRMOD_M_BAS = 0b100; //基址寻址 jmp [qbx + 1000h]
constexpr addrmod_t ADDRMOD_M_IDX = 0b101;  //变址寻址 jmp [qbx + qsi]
constexpr addrmod_t ADDRMOD_M_BXI = 0b110;  //基址变址寻址 jmp [qbx + qsi + 1000h]
constexpr addrmod_t ADDRMOD_M_SCA = 0b111; //比例变址寻址 jmp [qbx + qsi * scale + 1000h]

YABI_END
#endif