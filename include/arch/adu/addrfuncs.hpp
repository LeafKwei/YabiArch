#ifndef YABIARCH_ADDRFUNCS_HPP
#define YABIARCH_ADDRFUNCS_HPP

#include "def/reg.hpp"
#include "arch/adu/AddrFunc.hpp"
#include "arch/InstStruct.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "io/op/Op.hpp"

YABI_BEGIN

/* 名称声明 */
class OrderedIO;

/* 立即数寻址 */
inline iosize_t addrfunc_imm(RegTableIO *rtb, MemoryIO *mem, iosize_t iosize, OrderedIO **op){
    memaddr_t addr = rtb -> in(QIP, sizeof(memaddr_t));
    qword_t imm = mem -> in(addr, iosize);

    /* 设置IO对象的数据源 */
    Op::immop.setImm(imm, iosize);

    /* 将IO对象设置为操作数 */
    *op = &Op::immop;

    /* 返回从内存读取的字节数 */
    return iosize;
}



YABI_END
#endif