#ifndef YABI_DCU_HPP
#define YABI_DCU_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
class InstStruct;

/* DCU(DeCode Unit，译码单元)用于将二进制形式的指令基本信息解码到InstStruct结构体中 */
class DCU{
public:
    DCU(RegTableIO *rtb, MemoryIO *mem);
    void decode(InstStruct *ins);

private:
    RegTableIO *rtb_;
    MemoryIO *mem_;

    memunit_t readMemunit();
    void readOpcode(InstStruct *ins);
    void readAddrmod(InstStruct *ins);
};

YABI_END
#endif