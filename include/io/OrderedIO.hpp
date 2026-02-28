#ifndef YABI_ORDEREDIO_HPP
#define YABI_ORDEREDIO_HPP

#include "def/yabi.hpp"
#include "def/err.hpp"
#include "def/types.hpp"
YABI_BEGIN

/* 有序IO接口，用于向指令函数提供统一的操作数IO方式，并提供了向低地址、高地址有序移动的功能  */
class OrderedIO{
public:
    virtual ~OrderedIO() =default;
	virtual int ioid() const noexcept =0;                 //获取IO对象所属模块的ID
    virtual memaddr_t addr() const noexcept =0;  //获取当前输入/输出的寄存器编号/内存地址
    virtual iosize_t size() const noexcept =0;      //获取此IO对象的输入/输出字节数
    virtual void moveup() noexcept =0;              //向高地址方向移动size()字节，如果IO对象是寄存器或立即数，则此函数无效
    virtual void movedown() noexcept =0;         //向低地址方向移动size()字节，如果IO对象是寄存器或立即数，则此函数无效
	virtual qword_t in() =0;                                 //从当前寄存器/内存单位读取n字节
    virtual void        out(qword_t data) =0;        //向当前寄存器/内存单位输出n字节
};

YABI_END
#endif