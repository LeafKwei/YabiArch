#ifndef YABI_DIRADDR_HPP
#define YABI_DIRADDR_HPP

#include "def/types.hpp"
#include "io/op/MemopIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "kit/MemAgent.hpp"
YABI_BEGIN

class DIRAddr{
public:
    void operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op);
private:
    MemopIO memio_;
};

inline void DIRAddr::operator()(RegTableIO *rtb, MemAgent *agent, iosize_t opsize, OrderedIO **op){
    
}

YABI_END
#endif