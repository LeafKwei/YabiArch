#ifndef YABI_UNIIO_HPP
#define YABI_UNIIO_HPP

#include "def/yabi.hpp"
#include "def/err.hpp"
#include "def/types.hpp"
YABI_BEGIN

class UniIO{
    virtual ~UniIO() =default;
	virtual int ioid() const noexcept =0;             //获取IO对象所属模块的ID
    virtual errnum_t ioerr() const noexcept =0; //获取IO错误标记
    virtual void cleanerr() noexcept =0;              //清除错误标记
	virtual regsize_t in(regsize_t reg_addr_port, size_t n) noexcept =0;    //从指定的寄存器/地址/端口中读入n个字节，不可超过regsize_t的大小(允许各个实现固定输入字节大小)
    virtual void out(regsize_t reg_addr_port, regsize_t data, size_t n) noexcept =0; //向指定的寄存器/地址/端口中写入n个字节，不可超过regsize_t的大小(允许各个实现固定输出字节大小)
};

YABI_END
#endif