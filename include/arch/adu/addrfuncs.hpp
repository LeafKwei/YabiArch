#ifndef YABI_ADDRFUNCS_HPP
#define YABI_ADDRFUNCS_HPP

#include "def/types.hpp"
#include "io/op/ImmopIO.hpp"
#include "io/op/RegopIO.hpp"
#include "io/op/MemopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
#include "arch/adu/trans.hpp"
#include "arch/adu/AddrStruct.hpp"
YABI_BEGIN

/* 立即数寻址 */
inline void addr_IMM(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 从内存读取立即数 */
    auto imm = agent -> in(size);

    /* 将读取的立即数设置到IO对象 */
    ImmopIO *immop = dynamic_cast<ImmopIO*>(op);
    immop -> setImm(imm, size);
}

/* 寄存器寻址 */
inline void addr_REG(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 从内存中读取1字节，并将其低6bit取出作为寄存器号 */
    memaddr_t reg = (agent -> in(sizeof(byte_t))) & 0x3F; 

    /* 将寄存器号设置到IO对象 */
    RegopIO *regop = dynamic_cast<RegopIO*>(op);
    regop -> setReg(rtb, reg, size);
}

/* 存储器-直接寻址 */
inline void addr_DIR(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取需要读取的偏移量字节数 */
    auto offsize = trans2offsize(fields.offset);

    /* 按偏移量字节数从内存读取偏移量，然后连同MemIO对象设置到IO对象  */
    MemopIO *memop = dynamic_cast<MemopIO*>(op);
    memop -> setMem(agent -> memory(), agent -> in(offsize), size);
}

/* 存储器-间接寻址 */
inline void addr_IND(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取寄存器编号 */
    auto basereg = trans2reg(fields.base);

    /* 根据寄存器编号读取寄存器值作为偏移量并设置到IO对象 */
    MemopIO *memop = dynamic_cast<MemopIO*>(op);
    memop -> setMem(agent -> memory(), rtb -> in(basereg, sizeof(qword_t)), size);
}

/* 存储器-基址寻址  */
inline void addr_BAS(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 寄存器编号获取需要读取的偏移量字节数 */
    auto basereg = trans2reg(fields.base);
    auto offsize = trans2offsize(fields.offset);

    /* 从寄存器读取基址后从内存读取偏移量，然后将两者相加 */
    auto memaddr = rtb -> in(basereg, sizeof(qword_t)) + agent -> in(offsize);

    /* 将计算得到的地址设置到IO对象  */
    MemopIO *memop = dynamic_cast<MemopIO*>(op);
    memop -> setMem(agent -> memory(), memaddr, size);
}

/* 存储器-变址寻址 */
inline void addr_IDX(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取基址寄存器和变址寄存器编号 */
    auto basereg = trans2reg(fields.base);
    auto idxreg = trans2reg(fields.index);

    /* 从寄存器读取基址和变址，然后相加 */
    auto memaddr = rtb -> in(basereg, sizeof(qword_t)) + rtb -> in(idxreg, sizeof(qword_t));

    /* 将计算得到的地址设置到IO对象  */
    MemopIO *memop = dynamic_cast<MemopIO*>(op);
    memop -> setMem(agent -> memory(), memaddr, size);
}

/* 存储器-基址变址寻址  */
inline void addr_BXI(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取基址寄存器、变址寄存器编号、偏移量大小 */
    auto basereg = trans2reg(fields.base);
    auto idxreg = trans2reg(fields.index);
    auto offsize = trans2offsize(fields.offset);

    /* 从寄存器读取基址、变址、偏移量，然后相加 */
    auto memaddr = rtb -> in(basereg, sizeof(qword_t)) + rtb -> in(idxreg, sizeof(qword_t)) + agent -> in(offsize);

    /* 将计算得到的地址设置到IO对象  */
    MemopIO *memop = dynamic_cast<MemopIO*>(op);
    memop -> setMem(agent -> memory(), memaddr, size);
}

/* 存储器-比例变址寻址 */
inline void addr_SCA(RegTableIO *rtb, MemAgent *agent, iosize_t size, OrderedIO *op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取基址寄存器、变址寄存器编号、偏移量大小、比例 */
    auto basereg = trans2reg(fields.base);
    auto idxreg = trans2reg(fields.index);
    auto offsize = trans2offsize(fields.offset);
    auto scale = trans2scale(fields.scale);

    /* 从寄存器读取基址、变址、偏移量，将变址与比例相乘，最后将各项相加 */
    auto memaddr = rtb -> in(basereg, sizeof(qword_t)) + ((rtb -> in(idxreg, sizeof(qword_t))) * scale) + agent -> in(offsize);

    /* 将计算得到的地址设置到IO对象  */
    MemopIO *memop = dynamic_cast<MemopIO*>(op);
    memop -> setMem(agent -> memory(), memaddr, size);
}


YABI_END
#endif


