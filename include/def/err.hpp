#ifndef YABI_ERR_HPP
#define YABI_ERR_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 错误码 //////////////////////////
constexpr errnum_t OK = 0;
constexpr errnum_t EIO_REG = 50;
constexpr errnum_t EIO_MEM = 60;
constexpr errnum_t EIO_TERM = 100;  //终端IO错误

YABI_END
#endif