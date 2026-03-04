#ifndef YABI_BYTE_HPP
#define YABI_BYTE_HPP

#include <cassert>
#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 注意：此文件中的所有工具函数都应该以无符号数的形式对待参数，避免因参数为负数在移位或类型转换时使得高位bit位被补1                          //
// 需要小bit转大bit的位置，一律先将小bit转同bit宽度的无符号数，然后再扩展为大bit无符号数                                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 获取src指定位置的一个字节 */
inline byte_t getbyte(qword_t src, unsigned int pos) noexcept{
    uqword_t u = src;
    u = (u >> (pos * sizeof(byte_t))) & 0xFF;
    return static_cast<byte_t>(u);
}

/* 将字节b设置到src指定位置，返回设置后的src */
inline qword_t setbyte(qword_t src, byte_t b, unsigned int pos) noexcept{
    uqword_t u = src;
    uqword_t v = static_cast<ubyte_t>(b);
    u &= ~(static_cast<uqword_t>(0xFF) << (pos * sizeof(byte_t)));   //清空指定位置的字节
    u |= (v << (pos * sizeof(byte_t)));                                                     //将新字节左移指定位数后设置到src
    return static_cast<qword_t>(u);
}

/* 将src指定位置的字节清零，返回清零后的src */
inline qword_t clrbyte(qword_t src, unsigned int pos) noexcept{
    uqword_t u = src;
    u &= ~(static_cast<uqword_t>(0xFF) << (pos * sizeof(byte_t)));
    return static_cast<qword_t>(u);
}

YABI_END
#endif