#ifndef YABI_TYPES_HPP
#define YABI_TYPES_HPP

#include <cstdint>
#include "def/yabi.hpp"
YABI_BEGIN

using regsize_t = int64_t;
using memunit_t = int8_t;
using charunit_t = int8_t;
using addr_t      = uint64_t;
using iosize_t = uint64_t;

YABI_END
#endif