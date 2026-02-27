#ifndef YABI_ADDRMODER_HPP
#define YABI_ADDRMODER_HPP

#include "io/LinearIO.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "io/op/ImmopIO.hpp"
#include "io/op/RegopIO.hpp"
#include "io/op/MemopIO.hpp"
#include "arch/inst/InstStruct.hpp"
YABI_BEGIN

class Addrmoder{
public:
    int addrOn(const RegTableIO *rtb, const MemoryIO *mem, InstStruct *ins);  //根据InstStruct中的指令类型、寻址方式和操作数大小从内存中取出操作数并生成LinearIO指针保存到InstStruct，返回读取的字节数量以便虚拟机更新qip
};

YABI_END
#endif