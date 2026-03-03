#include "arch/mcu/MCU.hpp"
#include "arch/MachineInf.hpp"
#include "arch/InstStruct.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "def/reg.hpp"
#include "def/eflag.hpp"
#include "utility/bit.hpp"
YABI_BEGIN

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