#ifndef YABI_LINEARIO_HPP
#define YABI_LINEARIO_HPP

#include "def/yabi.hpp"
#include "def/err.hpp"
#include "def/types.hpp"
YABI_BEGIN

/* 线性IO接口，用于向指令函数提供统一的操作数IO方式，并提供了向低地址、高地址移动的功能  */
class LinearIO{
public:
    virtual ~LinearIO() =default;
	virtual int ioid() const noexcept =0;             //获取IO对象所属模块的ID
    virtual errnum_t ioerr() const noexcept =0; //获取IO错误标记
    virtual void cleanerr() noexcept =0;              //清除错误标记
    virtual regsize_t addr() const noexcept =0;  //获取当前输入/输出的寄存器编号/内存地址
    virtual iosize_t size() const noexcept =0;      //获取此IO对象的输入/输出字节数
    virtual void moveup() noexcept =0;              //向高地址方向移动size()字节，如果IO对象是寄存器，则此函数无效
    virtual void movedown() noexcept =0;         //向低地址方向移动size()字节，如果IO对象是寄存器，则此函数无效
	virtual regsize_t in() noexcept =0;                //从当前寄存器/内存单位读取n字节
    virtual void        out(regsize_t data) noexcept =0; //向当前寄存器/内存单位输出n字节
};

YABI_END
#endif