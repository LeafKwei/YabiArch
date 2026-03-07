#ifndef YABI_MCU_HPP
#define YABI_MCU_HPP

#include "def/yabi.hpp"
#include "def/types.hpp"
#include "arch/mcu/CntlFunc.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
struct MachineInf;
struct InstStruct;

/* MCU(Machine Control Unit，机器控制单元)负责在各阶段控制机器属性 */
class MCU{
public:
    MCU(RegTableIO &rtb, MemoryIO &mem);
    void control(MachineInf &inf, InstStruct &ins);

private:
    RegTableIO &rtb_;
    MemoryIO &mem_;
    std::vector<CntlFunc> cntlfuncs_;

private:
    void callEach(MachineInf &inf, InstStruct &ins);
    void registerCntlFuncs();
};

YABI_END
#endif