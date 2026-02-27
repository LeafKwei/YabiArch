#ifndef YABI_BIT_HPP
#define YABI_BIT_HPP

#include "def/types.hpp"
YABI_BEGIN

////////////////////////// bit位工具函数 //////////////////////////
inline bool hasbit(regunit_t src, regunit_t bit) noexcept{
    return (src & bit);
}

inline regunit_t setbit(regunit_t src, regunit_t bit) noexcept{
    return (src | bit);
}

inline regunit_t clrbit(regunit_t src, regunit_t bit) noexcept{
    return (src & (~bit));
}

YABI_END
#endif