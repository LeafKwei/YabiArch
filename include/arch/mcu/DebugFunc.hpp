#ifndef YABI_DEBUGFUNC_HPP
#define YABI_DEBUGFUNC_HPP

#include <functional>
#include "def/yabi.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;

/* 用户提供的debug函数，将在设置FLAG_DBG标志后调用 */
using DebugFunc = std::function<void(RegTableIO *rtb, MemoryIO *mem)>;

YABI_END
#endif