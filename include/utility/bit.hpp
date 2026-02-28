#ifndef YABI_BIT_HPP
#define YABI_BIT_HPP

#include "def/types.hpp"
YABI_BEGIN

////////////////////////// bit位工具函数 //////////////////////////
inline bool hasbit(qword_t src, qword_t bit) noexcept{
    return (src & bit);
}

inline qword_t setbit(qword_t src, qword_t bit) noexcept{
    return (src | bit);
}

inline qword_t clrbit(qword_t src, qword_t bit) noexcept{
    return (src & (~bit));
}

YABI_END
#endif