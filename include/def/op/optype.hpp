#ifndef YABI_OPTYPE_HPP
#define YABI_OPTYPE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 指令类型 //////////////////////////
constexpr optype_t OPTYPE_TIDY = 0b00;  //精简指令，无操作数
constexpr optype_t OPTYPE_ORDI = 0b01;  //普通指令，带有一个32位立即数
constexpr optype_t OPTYPE_COMP = 0b10; //复杂指令，带有一个控制块，需要根据控制块读取后续操作数

YABI_END
#endif