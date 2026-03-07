#ifndef YABI_OPTYPE_HPP
#define YABI_OPTYPE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 指令类型 //////////////////////////
constexpr optype_t OPTYPE_NOP = 0b00;  //无操作数指令
constexpr optype_t OPTYPE_SOP = 0b01;  //单操作数指令
constexpr optype_t OPTYPE_DOP = 0b10; //双操作数指令

YABI_END
#endif