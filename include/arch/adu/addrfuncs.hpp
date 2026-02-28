#ifndef YABIARCH_ADDRFUNCS_HPP
#define YABIARCH_ADDRFUNCS_HPP

#include "arch/adu/AddrFunc.hpp"
#include "arch/InstStruct.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "def/io/reg.hpp"
YABI_BEGIN

/* 名称声明 */
class OrderedIO;

/* 立即数寻址 */
inline iosize_t addrfunc_imm(RegTableIO *rtb, MemoryIO *mem, iosize_t iosize, OrderedIO **op){
    memaddr_t addr = rtb -> in(QIP, sizeof(memaddr_t));
    regunit_t imm = mem -> in(addr, iosize);

    /* 生成ImmIO对象 */
}



YABI_END
#endif