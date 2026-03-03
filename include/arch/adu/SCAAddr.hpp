#ifndef YABI_SCAADDR_HPP
#define YABI_SCAADDR_HPP

#include "def/types.hpp"
#include "io/op/MemopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
#include "arch/adu/trans.hpp"
#include "arch/adu/AddrStruct.hpp"
YABI_BEGIN

class SCAAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    MemopIO memio_;
};

inline void SCAAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取基址寄存器、变址寄存器编号、偏移量大小、比例 */
    auto basereg = trans2reg(fields.base);
    auto idxreg = trans2reg(fields.index);
    auto offsize = trans2offsize(fields.offset);
    auto scale = trans2scale(fields.scale);

    /* 从寄存器读取基址、变址、偏移量，将变址与比例相乘，最后将各项相加 */
    auto memaddr = rtb -> in(basereg, sizeof(qword_t)) + ((rtb -> in(idxreg, sizeof(qword_t))) * scale) + agent -> in(offsize);

    /* 设置MemopIO对象和op  */
    memio_.setMem(agent -> memory(), memaddr, opsize);
    *op = &memio_;
}

YABI_END
#endif