#ifndef YABI_OPCODE_HPP
#define YABI_OPCODE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

/**
 * 指令根据编码的前两bit分为精简指令(00)，简单指令(01)，复杂指令(10)，其中，编码11暂未使用，保留。
 * 如上所述，由于编码的限制，每种类别的指令不能超过64条，以免覆盖到其他类别的指令
 */

#define TIDYHEAD(code) (0 + code)              //0b00xxxxxx
#define ORDIHEAD(code) (64 + code)           //0b01xxxxxx
#define COMPHEAD(code) (128 + code)       //0b10xxxxxx
#define NONEHEAD(code) (192 + code)      //0b11xxxxxx保留，暂未使用

////////////////////////// 指令操作码(精简指令) //////////////////////////
constexpr opcode_t OPCODE_SHUT = TIDYHEAD(0); //shut
constexpr opcode_t OPCODE_DBG = TIDYHEAD(1);  //dbg

////////////////////////// 指令操作码(简单指令) //////////////////////////
constexpr opcode_t OPCODE_JMP = ORDIHEAD(0);   //jmp dst
constexpr opcode_t OPCODE_JMPE = ORDIHEAD(1);  //jmpe dst

////////////////////////// 指令操作码(复杂指令) //////////////////////////
constexpr opcode_t OPCODE_MOV = COMPHEAD(0);   //mov src, dst
constexpr opcode_t OPCODE_ADD = COMPHEAD(1);   //add src, dst
constexpr opcode_t OPCODE_SUB = COMPHEAD(2);    //sub src, dst
constexpr opcode_t OPCODE_CMP = COMPHEAD(7);   //cmp src, dst
constexpr opcode_t OPCODE_IN = COMPHEAD(15);      //in src, dst
constexpr opcode_t OPCODE_OUT = COMPHEAD(16);  //out src, dst

#undef TIDYHEAD
#undef ORDIHEAD
#undef COMPHEAD
#undef NONEHEAD

YABI_END
#endif