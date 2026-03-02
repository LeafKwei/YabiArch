#ifndef YABI_IMMADDR_HPP
#define YABI_IMMADDR_HPP

#include "def/types.hpp"
#include "io/op/ImmopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
YABI_BEGIN

class IMMAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    ImmopIO immio_;
};

inline void IMMAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    /* 从内存读取立即数 */
    auto imm = agent -> in(opsize);

    /* 更新io对象信息，并将IO对象的地址设置到操作数的IO对象指针 */
    immio_.setImm(imm, opsize);
    *op = &immio_;
}

YABI_END
#endif