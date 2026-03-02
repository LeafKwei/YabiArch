#ifndef YABI_ADDRSTRUCT_HPP
#define YABI_ADDRSTRUCT_HPP

#include "def/types.hpp"
YABI_BEGIN

struct AddrStruct{
    byte_t base;     //基址寄存器编号
    byte_t index;    //变址寄存器编号
    byte_t offset;    //偏移量大小(00字节、01字、10双字、11四字)
    byte_t scale;     //比例大小(00 1倍、01 2倍、10 4倍、11 8倍)

    AddrStruct() =default;
    AddrStruct(byte_t field);
};

inline AddrStruct::AddrStruct(byte_t field){
    base = field & 0xC0;
    index = field & 0x30;
    offset = field & 0x0C;
    scale = field & 0x03;
};

YABI_END
#endif