#ifndef YABI_IDXADDR_HPP
#define YABI_IDXADDR_HPP

#include "def/types.hpp"
#include "io/op/MemopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
#include "arch/adu/trans.hpp"
#include "arch/adu/AddrStruct.hpp"
YABI_BEGIN

class IDXAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    MemopIO memio_;
};

inline void IDXAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取基址寄存器和变址寄存器编号 */
    auto basereg = trans2reg(fields.base);
    auto idxreg = trans2reg(fields.index);

    /* 从寄存器读取基址和变址，然后相加 */
    auto memaddr = rtb -> in(basereg, sizeof(qword_t)) + rtb -> in(idxreg, sizeof(qword_t));

    /* 设置MemopIO对象和op  */
    memio_.setMem(agent -> memory(), memaddr, opsize);
    *op = &memio_;
}

YABI_END
#endif