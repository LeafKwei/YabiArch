#ifndef YABI_OPCODE_HPP
#define YABI_OPCODE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

/**
 * 指令根据编码的前两bit分为无操作数指令(00)，单操作数指令(01)，双操作数指令(10)，其中，编码11暂未使用，保留。
 * 如上所述，由于编码的限制，每种类别的指令不能超过64条，以免覆盖到其他类别的指令
 */

#define NOPHEAD(code) (0 + code)              //0b00xxxxxx
#define SOPHEAD(code) (64 + code)           //0b01xxxxxx
#define DOPHEAD(code) (128 + code)         //0b10xxxxxx
//#define XXXHEAD(code) (192 + code)      //0b11xxxxxx保留，暂未使用

////////////////////////// 指令操作码(无操作数指令) //////////////////////////
constexpr opcode_t OPCODE_SHUT = NOPHEAD(0); //shut
constexpr opcode_t OPCODE_DBG = NOPHEAD(1);  //dbg

////////////////////////// 指令操作码(单操作数指令) //////////////////////////
constexpr opcode_t OPCODE_JMP = SOPHEAD(0);   //jmp dst
constexpr opcode_t OPCODE_JMPE = SOPHEAD(1);  //jmpe dst

////////////////////////// 指令操作码(双操作数指令) //////////////////////////
constexpr opcode_t OPCODE_MOV = DOPHEAD(0);   //mov src, dst
constexpr opcode_t OPCODE_ADD = DOPHEAD(1);   //add src, dst
constexpr opcode_t OPCODE_SUB = DOPHEAD(2);    //sub src, dst
constexpr opcode_t OPCODE_CMP = DOPHEAD(7);   //cmp src, dst
constexpr opcode_t OPCODE_IN = DOPHEAD(15);      //in src, dst
constexpr opcode_t OPCODE_OUT = DOPHEAD(16);  //out src, dst

#undef NOPHEAD
#undef SOPHEAD
#undef DOPHEAD
#undef NONEHEAD

YABI_END
#endif