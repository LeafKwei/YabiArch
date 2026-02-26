#ifndef YABI_OPCODE_HPP
#define YABI_OPCODE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 指令操作码 //////////////////////////
constexpr opcode_t OPCODE_MOV = 0x00;   //mov src, dst

constexpr opcode_t OPCODE_ADD = 0x01;   //add src, dst
constexpr opcode_t OPCODE_SUB = 0x02;    //sub src, dst

constexpr opcode_t OPCODE_CMP = 0x08;   //cmp src, dst
constexpr opcode_t OPCODE_JMP = 0x09;    //jmp dst
constexpr opcode_t OPCODE_JMPE = 0x0a;  //jmpe dst
constexpr opcode_t OPCODE_JMPL = 0x0b;  //jmpl dst
constexpr opcode_t OPCODE_JMPG = 0x0c;  //jmpg dst

constexpr opcode_t OPCODE_IN = 0x10;      //in src, dst
constexpr opcode_t OPCODE_OUT = 0x11;  //out src, dst

YABI_END
#endif