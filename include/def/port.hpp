#ifndef YABI_PORT_HPP
#define YABI_PORT_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 终端端口 //////////////////////////
constexpr memaddr_t PORT_TERM_IN = 0;      //标准输入
constexpr memaddr_t PORT_TERM_OUT = 1;  //标准输出
constexpr memaddr_t PORT_TERM_ERR = 2;   //标准错误

YABI_END
#endif