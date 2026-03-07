#ifndef YABI_IOBUNDLE_HPP
#define YABI_IOBUNDLE_HPP

#include "io/op/ImmopIO.hpp"
#include "io/op/RegopIO.hpp"
#include "io/op/MemopIO.hpp"
YABI_BEGIN

/* 将操作数IO对象集中在一起，便于ADU管理  */
struct IOBundle{
    ImmopIO immop;
    RegopIO  regop;
    MemopIO memop;
};


YABI_END
#endif