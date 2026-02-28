#ifndef YABI_INSTSTRUCT_HPP
#define YABI_INSTSTRUCT_HPP

#include "def/types.hpp"
#include "io/OrderedIO.hpp"
YABI_BEGIN

/* 指令结构体，将二进制形式的指令结构化 */
struct InstStruct{
    optype_t optype;
    opcode_t opcode;
    opsize_t  opsize;
    addrmod_t modsrc;
    addrmod_t moddst;
    OrderedIO *src;
    OrderedIO *dst;
};

YABI_END
#endif