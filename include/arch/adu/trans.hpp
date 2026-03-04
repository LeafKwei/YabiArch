#ifndef YABI_TRANS_HPP
#define YABI_TRANS_HPP

#include "def/types.hpp"
#include "def/reg.hpp"
YABI_BEGIN

inline memaddr_t trans2offsize(byte_t b) noexcept{
    int size[] = {sizeof(byte_t), sizeof(word_t), sizeof(dword_t), sizeof(qword_t)};
    return size[b & 0b11];    //使用数组并将b作为索引直接查询大小以提高效率
}

inline byte_t trans2scale(byte_t b) noexcept{
    int size[] = {sizeof(byte_t), sizeof(word_t), sizeof(dword_t), sizeof(qword_t)};
    return size[b & 0b11];    //使用数组并将b作为索引直接查询大小以提高效率
}

inline memaddr_t trans2reg(byte_t b) noexcept{
    return b; //字段值直接与寄存器编号对应，因此直接返回即可
}

YABI_END
#endif