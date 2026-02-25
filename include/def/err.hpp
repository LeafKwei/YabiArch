#ifndef YABI_ERR_HPP
#define YABI_ERR_HPP

#include <stdexcept>
#include "def/yabi.hpp"
YABI_BEGIN

////////////////////////// 错误码 //////////////////////////
using errnum_t = int; 

constexpr errnum_t OK = 0;
constexpr errnum_t EIO_REG = 50;
constexpr errnum_t EIO_MEM = 60;
constexpr errnum_t EIO_TERM = 100;  //终端IO错误

YABI_END
#endif