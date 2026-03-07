#ifndef YABI_CNTLFUNCS_HPP
#define YABI_CNTLFUNCS_HPP

#include "def/reg.hpp"
#include "def/eflag.hpp"
#include "utility/bit.hpp"
#include "arch/mcu/CntlFunc.hpp"
#include "arch/zeta/InstStruct.hpp"
#include "arch/zeta/MachineInf.hpp"
YABI_BEGIN

/* 停机标志检测函数，如果停机标志置位，则将MachineInf的alive置false */
inline void cntl_check_shutflag(RegTableIO &rtb, MemoryIO &mem, MachineInf &inf, InstStruct &ins){
    auto qef = rtb.in(QEF, sizeof(qword_t));
    if(hasbit(qef, FLAG_SHUT)){
        inf.alive = false;
    }
}

/* 调试标志检测函数，如果调试标志置位，则调用调试函数 */
inline void cntl_check_dbgflag(RegTableIO &rtb, MemoryIO &mem, MachineInf &inf, InstStruct &ins){
    auto qef = rtb.in(QEF, sizeof(qword_t));
    if(hasbit(qef, FLAG_DBG)){
        inf.dbg(rtb, mem, ins);
    }
}

YABI_END
#endif