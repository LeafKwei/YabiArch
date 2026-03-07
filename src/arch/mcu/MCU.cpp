#include "arch/mcu/MCU.hpp"
#include "arch/MachineInf.hpp"
#include "arch/InstStruct.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "def/reg.hpp"
#include "def/eflag.hpp"
#include "utility/bit.hpp"
YABI_BEGIN

/**
 * 机器控制过程可概括为：MCU遍历每一个已注册的控制函数，然后将RegTableIO、MemoryIO、MachineInf、InstStruct全部传递给该函数，
 * 由其处理具体的控制行为
 */

MCU::MCU(RegTableIO *rtb, MemoryIO *mem)
    : rtb_(rtb)
    , mem_(mem)
{

}

void MCU::control(MachineInf *inf, InstStruct *ins){
    if(hasbit(rtb_ -> in(QEF, sizeof(qword_t)), FLAG_SHUT)){
        inf -> alive = false;
    }
}

YABI_END