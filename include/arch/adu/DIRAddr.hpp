#ifndef YABI_DIRADDR_HPP
#define YABI_DIRADDR_HPP

#include "def/types.hpp"
#include "io/op/MemopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
#include "arch/adu/trans.hpp"
#include "arch/adu/AddrStruct.hpp"
YABI_BEGIN

class DIRAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    MemopIO memio_;
};

inline void DIRAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    /* 获取寻址指示字节并将bit解析到各个字段 */
    AddrStruct fields(agent -> in(sizeof(byte_t)));

    /* 获取需要读取的偏移量字节数 */
    auto offsize = trans2offsize(fields.offset);

    /* 从内存读取偏移量并设置MemopIO对象，然后将其地址设置到op  */
    memio_.setMem(agent -> memory(), agent -> in(offsize), opsize);
    *op = &memio_;
}

YABI_END
#endif