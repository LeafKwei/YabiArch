#ifndef YABI_MACHINE_HPP
#define YABI_MACHINE_HPP

#include <unordered_map>
#include "arch/dcu/DCU.hpp"
#include "arch/adu/ADU.hpp"
#include "arch/ixu/IXU.hpp"
#include "arch/mcu/MCU.hpp"
#include "arch/InstStruct.hpp"
#include "arch/MachineInf.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "io/dev/PeriDeviceIO.hpp"
YABI_BEGIN

class YabiMachine{
public:
    YabiMachine();
    void load(const byte_t *program, seqsize_t n, memaddr_t addr);       //加载一段程序到指定内存
    void setEntry(memaddr_t addr);    //设置程序入口的内存地址
    void setDebug(DebugFunc dbg);  //设置debug函数
    void start();      //开始执行程序
    void restart();   //重新执行程序

private:
    memaddr_t entry_;
    InstStruct ins_;
    MachineInf inf_;

    /* 设备 */
    RegTableIO rtb_;
    MemoryIO mem_;
    PeriDeviceIO dev_;
    
    /* 核心组件 */
    DCU dcu_;
    ADU adu_;
    IXU  ixu_;
    MCU mcu_;
};

YABI_END
#endif