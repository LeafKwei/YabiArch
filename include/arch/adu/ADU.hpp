#ifndef YABI_ADU_HPP
#define YABI_ADU_HPP

#include "def/yabi.hpp"
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
};

YABI_END
#endif