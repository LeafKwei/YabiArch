#ifndef YABI_ADU_HPP
#define YABI_ADU_HPP

#include <unordered_map>
#include "def/yabi.hpp"
#include "arch/adu/AddrFunc.hpp"
#include "def/addrmod.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
class InstStruct;

/* ADU(ADdressing Unit，寻址单元)按照寻址方式生成IO对象并设置到InstStruct中 */
class ADU{
public:
    ADU(RegTableIO *rtb, MemoryIO *mem);
    void addressing(InstStruct *ins);

private:
    RegTableIO *rtb_;
    MemoryIO *mem_;
    std::unordered_map<addrmod_t, AddrFunc> addrmods_;

private:
    void registerAddrFuncs();
    iosize_t opsize2iosize(opsize_t opsize);
};

YABI_END
#endif