#ifndef YABI_OPSIZE_HPP
#define YABI_OPSIZE_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 操作数位宽 //////////////////////////
constexpr opsize_t OPSIZE_BYTE = 0b00; //8位
constexpr opsize_t OPSIZE_WORD = 0b01; //16位
constexpr opsize_t OPSIZE_DWOR = 0b10; //32位
constexpr opsize_t OPSIZE_QWOR = 0b11; //64位

YABI_END
#endif