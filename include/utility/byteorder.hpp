#ifndef YABI_BYTEORDER_HPP
#define YABI_BYTEORDER_HPP

#include <cassert>
#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 大小端无关工具函数 //////////////////////////
/**
 * YabiArch使用的是小端字节序，因此当虚拟机运行于大端机器时，如果需要对底层字节进行操作，那么就需要将用户指定的字节位置
 * 转换为大端字节序的位置
 */
inline int localpos(unsigned int pos) noexcept{
    /* 首先确保pos的大小不超过虚拟机的最大字长 */
    assert(pos < sizeof(regunit_t));

    /* 物理机是小端机器时，可直接返回小端位置 */
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN_
    return pos;
#else
    return (sizeof(regunit_t) - 1) - pos;
#endif
}

/* 以大小端无关方式获取src指定位置的一个字节 */
inline charunit_t getbyte(regunit_t src, unsigned int pos) noexcept{
    charunit_t *p = reinterpret_cast<charunit_t*>(&src) + localpos(pos);
    return *p; 
}

/* 以大小端无关方式将字节b设置到src指定位置，返回设置后的src */
inline regunit_t setbyte(regunit_t src, charunit_t b, unsigned int pos) noexcept{
    charunit_t *p = reinterpret_cast<charunit_t*>(&src) + localpos(pos);
    *p = b;
    return src;
}

/* 以大小端无关方式将src指定位置的字节清零，返回清零后的src */
inline regunit_t clrbyte(regunit_t src, unsigned int pos) noexcept{
    charunit_t *p = reinterpret_cast<charunit_t*>(&src) + localpos(pos);
    *p = 0;
    return src;
}

YABI_END
#endif