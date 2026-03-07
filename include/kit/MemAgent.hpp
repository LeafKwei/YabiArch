#ifndef YABI_MEMAGENT_HPP
#define YABI_MEMAGENT_HPP

#include "def/types.hpp"
YABI_BEGIN

/* 名称声明 */
class RegTableIO;
class MemoryIO;

/* MemAgent主要是用于指令解码和操作数寻址阶段的一个代理类，在从MemoryIO中读取字节时可以同步更新RegTableIO中的QIP寄存器 */
class MemAgent{
public:
    MemAgent(RegTableIO &rtb, MemoryIO &mem);
	qword_t in(iosize_t n);      //从QIP指向的内存位置读取n个字节，同步更新QIP
    void undo();                      //撤销上一次读取时对QIP的更改
    MemoryIO* memory();     //获取MemoryIO的指针

private:
    qword_t       qip_;
    RegTableIO &rtb_;
    MemoryIO  &mem_;
};

YABI_END
#endif