#ifndef YABI_IXU_HPP
#define YABI_IXU_HPP

#include <unordered_map>
#include "arch/ixu/InstFunc.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
class PeriDeviceIO;
class InstStruct;

/* IXU(Instruction eXecution Unit，指令执行单元)用于执行虚拟机给定的指令 */
class IXU{
public:
    IXU(RegTableIO *rtb, MemoryIO *mem, PeriDeviceIO *dev);
    void execute(InstStruct *ins);

private:
    RegTableIO *rtb_;
    MemoryIO *mem_;
    PeriDeviceIO *dev_;
    std::unordered_map<opcode_t, InstFunc> tidyinst_;    //精简指令
    std::unordered_map<opcode_t, InstFunc> ordinst_;     //简单指令
    std::unordered_map<opcode_t, InstFunc> compinst_; //复杂指令

private:
    void registerTidyInstructions();
    void registerOrdiInstructions();
    void registerCompInstructions();
};

YABI_END
#endif