#ifndef YABI_ADDRMD_HPP
#define YABI_ADDRMD_HPP

#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 寻址方式 //////////////////////////
//注：YabiArch中的操作数顺序为(src, dst)
constexpr addrmd_t ADDRMD_IMM = 0x0;  //立即数寻址 jmp 1000h
constexpr addrmd_t ADDRMD_REG = 0x1;   //寄存器寻址 jmp qax

/* 存储器寻址 */
constexpr addrmd_t ADDRMD_M_DIR = 0x2; //直接寻址 jmp [1000h]
constexpr addrmd_t ADDRMD_M_IND = 0x3; //间接寻址 jmp [qbx]
constexpr addrmd_t ADDRMD_M_BAS = 0x4; //基址寻址 jmp [qbx + 1000h]
constexpr addrmd_t ADDRMD_M_IDX = 0x5;  //变址寻址 jmp [qbx + qsi]
constexpr addrmd_t ADDRMD_M_BXI = 0x6;  //基址变址寻址 jmp [qbx + qsi + 1000h]
constexpr addrmd_t ADDRMD_M_SCA = 0x7; //比例变址寻址 jmp [qbx + qsi * scale + 1000h]

YABI_END
#endif