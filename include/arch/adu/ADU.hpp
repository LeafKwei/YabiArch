#ifndef YABI_ADU_HPP
#define YABI_ADU_HPP

#include "def/yabi.hpp"
#include "def/addrmod.hpp"
#include "arch/adu/IOBundle.hpp"
#include "arch/adu/AddrFunc.hpp"

YABI_BEGIN

/* 名称声明 */
struct InstStruct;

/* ADU(ADdressing Unit，寻址单元)按照寻址方式生成IO对象并设置到InstStruct中 */
class ADU{
public:
    ADU(RegTableIO &rtb, MemoryIO &mem);
    void addressing(InstStruct &ins);

private:
    using AddrFuncMap = std::unordered_map<addrmod_t, AddrFunc>;

private:
    RegTableIO &rtb_;
    MemoryIO &mem_;
    IOBundle    srcbundle_;
    IOBundle    dstbundle_;
    AddrFuncMap addrfuncs_;

private:
    void addressingSRC(InstStruct &ins);
    void addressingDST(InstStruct &ins);
    void addressingOn(addrmod_t mod, iosize_t size, OrderedIO *op);
    OrderedIO* selectIO(IOBundle *bundle, addrmod_t mod);
    void registerAddrFuncs();
    iosize_t opsize2iosize(opsize_t opsize);
};

YABI_END
#endif