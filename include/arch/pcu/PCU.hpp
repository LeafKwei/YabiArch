#ifndef YABI_PCU_HPP
#define YABI_PCU_HPP

#include <unordered_map>
#include "def/yabi.hpp"
#include "def/types.hpp"
#include "arch/pcu/PreckFunc.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;
struct InstStruct;

/* PCU(Pre-Check Unit，预检查单元)负责在指令执行前核对指令的编码和寻址方式是否正常 */
class PCU{
public:
    PCU(RegTableIO *rtb, MemoryIO *mem);
    void precheck(InstStruct *ins);

private:
    RegTableIO *rtb_;
    MemoryIO *mem_;
    std::unordered_map<opcode_t, PreckFunc> tidyinst_;    //精简指令
    std::unordered_map<opcode_t, PreckFunc> ordinst_;     //简单指令
    std::unordered_map<opcode_t, PreckFunc> compinst_; //复杂指令
};

YABI_END
#endif