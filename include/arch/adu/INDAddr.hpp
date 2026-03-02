#ifndef YABI_INDADDR_HPP
#define YABI_INDADDR_HPP

#include "def/types.hpp"
#include "io/op/MemopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
#include "arch/adu/trans.hpp"
#include "arch/adu/AddrStruct.hpp"
YABI_BEGIN

class INDAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    MemopIO memio_;
};

inline void INDAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取寄存器编号 */
    auto basereg = trans2reg(fields.base);

    /* 从寄存器读取偏移量并设置MemopIO对象，然后将其地址设置到op  */
    memio_.setMem(agent -> memory(), rtb -> in(basereg, sizeof(qword_t)), opsize);
    *op = &memio_;
}

YABI_END
#endif