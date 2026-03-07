#ifndef YABI_MACHINEINF_HPP
#define YABI_MACHINEINF_HPP

#include "def/types.hpp"
#include "io/OrderedIO.hpp"
#include "mcu/DebugFunc.hpp"
YABI_BEGIN

/* 保存机器的各种属性 */
struct MachineInf{
    bool alive;             //机器是否继续运行
    DebugFunc dbg;   //debug函数
};

YABI_END
#endif