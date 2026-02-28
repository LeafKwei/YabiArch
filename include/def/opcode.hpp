#ifndef YABI_OPCODE_HPP
#define YABI_OPCODE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 指令操作码(精简指令) //////////////////////////
constexpr opcode_t OPCODE_SHUT = 0x00;  //shut

////////////////////////// 指令操作码(简单指令) //////////////////////////
constexpr opcode_t OPCODE_JMP = 0x00;    //jmp dst
constexpr opcode_t OPCODE_JMPE = 0x01;  //jmpe dst
constexpr opcode_t OPCODE_JMPL = 0x02;  //jmpl dst
constexpr opcode_t OPCODE_JMPG = 0x03;  //jmpg dst

////////////////////////// 指令操作码(复杂指令) //////////////////////////
constexpr opcode_t OPCODE_MOV = 0x00;   //mov src, dst
constexpr opcode_t OPCODE_ADD = 0x01;   //add src, dst
constexpr opcode_t OPCODE_SUB = 0x02;    //sub src, dst
constexpr opcode_t OPCODE_CMP = 0x06;   //cmp src, dst
constexpr opcode_t OPCODE_IN = 0x10;      //in src, dst
constexpr opcode_t OPCODE_OUT = 0x11;  //out src, dst

YABI_END
#endif