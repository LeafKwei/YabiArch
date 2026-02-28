#include "io/op/ImmopIO.hpp"
#include "io/op/RegopIO.hpp"
#include "io/op/MemopIO.hpp"
YABI_BEGIN

struct Op{
    static ImmopIO immop;
    static RegopIO regop;
    static MemopIO memop;
};

YABI_END