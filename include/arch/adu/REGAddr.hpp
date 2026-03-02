#ifndef YABI_REGADDR_HPP
#define YABI_REGADDR_HPP

#include "def/types.hpp"
#include "io/op/RegopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
YABI_BEGIN

class REGAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    RegopIO regio_;
};

inline void REGAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    /* 从内存中读取1字节，并将其低6bit取出作为寄存器号 */
    memaddr_t reg = (agent -> in(sizeof(byte_t))) & 0x3F; 

    /* 使用寄存器号生成IO对象并设置到op */
    regio_.setReg(rtb, reg, opsize);
    *op = &regio_;
}

YABI_END
#endif