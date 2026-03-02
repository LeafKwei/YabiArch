#ifndef YABI_BASADDR_HPP
#define YABI_BASADDR_HPP

#include "def/types.hpp"
#include "io/op/MemopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
#include "arch/adu/trans.hpp"
#include "arch/adu/AddrStruct.hpp"
YABI_BEGIN

class BASAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    MemopIO memio_;
};

inline void BASAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 寄存器编号获取需要读取的偏移量字节数 */
    auto basereg = trans2reg(fields.base);
    auto offsize = trans2offsize(fields.offset);

    /* 从寄存器读取基址后从内存读取偏移量，然后将两者相加 */
    auto memaddr = rtb -> in(basereg, sizeof(qword_t)) + agent -> in(offsize);

    /* 设置MemopIO对象和op  */
    memio_.setMem(agent -> memory(), memaddr, opsize);
    *op = &memio_;
}

YABI_END
#endif