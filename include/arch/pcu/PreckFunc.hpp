#ifndef YABIARCH_PRECKFUNC_HPP
#define YABIARCH_PRECKFUNC_HPP

#include <functional>
#include "def/types.hpp"
YABI_BEGIN

/* 名称声明 */
struct InstStruct;

/* 操作码检查函数类型，检查操作码及其寻址方式是否正确 */
using PreckFunc = std::function<void(InstStruct *ins)>;

YABI_END
#endif