#ifndef YABI_TYPES_HPP
#define YABI_TYPES_HPP

#include <cstdint>
#include "def/yabi.hpp"
YABI_BEGIN

/////////////////////////// 通用类型 //////////////////////////////////
using memunit_t = int8_t; //内存单元大小
using charunit_t = int8_t;  //单字符大小
using seqsize_t = uint64_t; //序列长度
using errnum_t = int;        //错误码
using memaddr_t = int64_t; //地址
using iosize_t = uint8_t;    //OrderedIO、RanomdIO时的数据长度

////////////////////////// 机器支持的数据宽度 ////////////////////////////
using byte_t = int8_t;     //单字节大小
using word_t = int16_t;  //单字大小
using dword_t = int32_t; //双字大小
using qword_t = int64_t; //四字大小
using maxword_t = qword_t; //虚拟机支持的最大字长

////////////////////////// 指令相关 //////////////////////////
using opmode_t = uint8_t; //指令模式
using optype_t = uint8_t;   //指令类型
using opcode_t = uint8_t;  //指令操作码
using opsize_t = uint8_t; //操作数大小
using addrmod_t = uint8_t;   //寻址方式

YABI_END
#endif