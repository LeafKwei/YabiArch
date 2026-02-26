#ifndef YABI_RANDIO_HPP
#define YABI_RANDIO_HPP

#include "def/yabi.hpp"
#include "def/err.hpp"
#include "def/types.hpp"
YABI_BEGIN

/* 随机IO接口，将寄存器、内存、设备的输入输出统一为相同的方式 */
class RandIO{
public:
    virtual ~RandIO() =default;
	virtual int ioid() const noexcept =0;             //获取IO对象所属模块的ID
    virtual errnum_t ioerr() const noexcept =0; //获取IO错误标记
    virtual void cleanerr() noexcept =0;              //清除错误标记
	virtual regsize_t in(memaddr_t reg_addr_port, iosize_t n) noexcept =0;    //从指定的寄存器/地址/端口中读入n个字节，不可超过regsize_t的大小(允许各个实现固定输入字节大小)
    virtual void        out(memaddr_t reg_addr_port, regsize_t data, iosize_t n) noexcept =0; //向指定的寄存器/地址/端口中写入n个字节，不可超过regsize_t的大小(允许各个实现固定输出字节大小)
};

YABI_END
#endif