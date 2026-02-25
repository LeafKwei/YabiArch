#ifndef YABI_PORT_HPP
#define YABI_PORT_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 终端端口 //////////////////////////
constexpr addr_t PORT_TERM_IN = 0;
constexpr addr_t PORT_TERM_OUT = 1;
constexpr addr_t PORT_TERM_ERR = 2;

YABI_END
#endif