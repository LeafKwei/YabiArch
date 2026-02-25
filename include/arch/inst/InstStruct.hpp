#ifndef YABI_INSTSTRUCT_HPP
#define YABI_INSTSTRUCT_HPP

#include "def/types.hpp"
#include "def/opcode.hpp"
YABI_BEGIN

struct InstStruct{
    bool lflag;                 //长指令标志
    opcode_t opcode;    //操作码
    opcomb_t opcomb; //操作数组合
    opsize_t op1size;     //操作数1大小
    opsize_t op2size;     //操作数2大小
    regsize_t op1;          //操作数1
    regsize_t op2;          //操作数2
};

YABI_END
#endif