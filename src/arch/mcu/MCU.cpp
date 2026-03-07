#include "def/err.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "arch/mcu/MCU.hpp"
#include "arch/mcu/cntlfuncs.hpp"
#include "arch/zeta/MachineInf.hpp"
#include "arch/zeta/InstStruct.hpp"
YABI_BEGIN

/**
 * 机器控制过程可概括为：MCU遍历每一个已注册的控制函数，然后将RegTableIO、MemoryIO、MachineInf、InstStruct全部传递给该函数，
 * 由其处理具体的控制行为
 */

MCU::MCU(RegTableIO &rtb, MemoryIO &mem)
    : rtb_(rtb)
    , mem_(mem)
{
    registerCntlFuncs();
}

void MCU::control(MachineInf &inf, InstStruct &ins){
    try{
        callEach(inf, ins);
    }
    catch(std::exception &e){
        throw YabiExcept(ERRMCU, e.what());
    }
}

void MCU::callEach(MachineInf &inf, InstStruct &ins){
    for(auto &cntl : cntlfuncs_){
        cntl(rtb_, mem_, inf, ins);
    }
}

void MCU::registerCntlFuncs(){
    cntlfuncs_.push_back(cntl_check_shutflag);
    cntlfuncs_.push_back(cntl_check_dbgflag);
}

YABI_END