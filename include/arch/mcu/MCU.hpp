#ifndef YABI_MCU_HPP
#define YABI_MCU_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
struct MachineInf;

/* MCU(Machine Control Unit，机器控制单元)负责在各阶段控制机器属性 */
class MCU{
public:
    MCU(RegTableIO *rtb, MemoryIO *mem);
    void control(MachineInf *inf);

private:
    RegTableIO *rtb_;
    MemoryIO *mem_;
};

YABI_END
#endif