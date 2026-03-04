#ifndef YABI_IXU_HPP
#define YABI_IXU_HPP

#include <vector>
#include "def/yabi.hpp"
#include "def/types.hpp"
#include "arch/ixu/InstFunc.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
class PeriDeviceIO;
struct InstStruct;

/* IXU(Instruction eXecution Unit，指令执行单元)用于执行虚拟机给定的指令 */
class IXU{
public:
    IXU(RegTableIO *rtb, MemoryIO *mem, PeriDeviceIO *dev);
    void execute(InstStruct *ins);

private:
    RegTableIO *rtb_;
    MemoryIO *mem_;
    PeriDeviceIO *dev_;
    std::vector<InstFunc> inst_;

private:
    void registerTidyInstructions();
    void registerOrdiInstructions();
    void registerCompInstructions();
};

YABI_END
#endif