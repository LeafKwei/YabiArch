#ifndef YABIARCH_INSTFUNCS_HPP
#define YABIARCH_INSTFUNCS_HPP

#include "def/reg.hpp"
#include "def/eflag.hpp"
#include "arch/zeta/InstStruct.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
#include "io/dev/PeriDeviceIO.hpp"
YABI_BEGIN

/////////////////////////////////无操作数指令///////////////////////////////
//shut：将QEF置FLAG_SHUT
inline void inst_nop_shut(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto qef = rtb.in(QEF, sizeof(qword_t));
    qef |= FLAG_SHUT;
    rtb.out(QEF, qef, sizeof(qword_t));
}

//dbg：将QEF置FLAG_DBG
inline void inst_nop_dbg(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto qef = rtb.in(QEF, sizeof(qword_t));
    qef |= FLAG_DBG;
}

/////////////////////////////////单操作数指令///////////////////////////////
//jmp dst：无条件跳转到dst指定的地址(通过设置QIP)
inline void inst_sop_jmp(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto memaddr = ins.dst -> in();
    rtb.out(QIP, memaddr, sizeof(qword_t));
}

//jmpe dst：QCX为0时，跳转到dst指定的地址(通过设置QIP)
inline void inst_sop_jmpe(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto qcx = rtb.in(QCX, sizeof(qword_t));
    auto memaddr = ins.dst -> in();

    if(qcx == 0){
        rtb.out(QIP, memaddr, sizeof(qword_t));
    }
}

/////////////////////////////////双操作数指令///////////////////////////////
//mov src, dst：将源操作数src拷贝到目的操作数dst
inline void inst_dop_mov(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto src = ins.src -> in();
    ins.dst -> out(src);
}

//add src, dst：将源操作数与目的操作数相加，结果保存至目的操作数
inline void inst_dop_add(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto src = ins.src -> in();
    auto dst = ins.dst -> in();
    ins.dst -> out(src + dst);
}

//sub src, dst：将源操作数与目的操作数相减，结果保存至目的操作数
inline void inst_dop_sub(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto src = ins.src -> in();
    auto dst = ins.dst -> in();
    ins.dst -> out(src - dst);
}

//cmp src, dst：将源操作数与目的操作数相减，结果保存至QCX寄存器
inline void inst_dop_cmp(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto src = ins.src -> in();
    auto dst = ins.dst -> in();
    rtb.out(QCX, src - dst, sizeof(qword_t));
}

//in src, dst：从源操作数对应的端口的设备中读取数据，保存至目的操作数
inline void inst_dop_in(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto port = ins.src -> in();
    auto data = dev.in(port, sizeof(byte_t));
    ins.dst -> out(data);
}

//out src, dst：将源操作数写入到目的操作数对应的端口的设备中
inline void inst_dop_out(RegTableIO &rtb, MemoryIO &mem, PeriDeviceIO &dev, InstStruct &ins){
    auto data = ins.src -> in();
    auto port = ins.dst -> in();
    dev.out(port, data, sizeof(byte_t));
}

YABI_END
#endif