#ifndef YABI_EFLAG_HPP
#define YABI_EFLAG_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

constexpr qword_t FLAG_SHUT = 1;  //停机标志
constexpr qword_t FLAG_DBG   = 1 << 1;  //debug标志

YABI_END
#endif