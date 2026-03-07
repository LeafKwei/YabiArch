#ifndef YABI_INSTSTRUCT_HPP
#define YABI_INSTSTRUCT_HPP

#include "def/types.hpp"
#include "io/OrderedIO.hpp"
YABI_BEGIN

/* 指令结构体，将二进制形式的指令结构化 */
struct InstStruct{
    optype_t optype;       //指令类型
    opcode_t opcode;     //指令操作码
    opsize_t  opsize;       //操作数大小
    addrmod_t modsrc;  //源操作数寻址方式
    addrmod_t moddst;  //目的操作数寻址方式
    OrderedIO *src;        //源操作数IO对象
    OrderedIO *dst;        //目的操作数IO对象
};

YABI_END
#endif