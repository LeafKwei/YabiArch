#ifndef YABI_ERR_HPP
#define YABI_ERR_HPP

#include <stdexcept>
#include "def/yabi.hpp"
#include "def/types.hpp"
YABI_BEGIN

////////////////////////// 异常 //////////////////////////
class YabiExcept : std::logic_error{
public:
    YabiExcept(errnum_t err, const std::string &msg="") : logic_error(msg), err_(err){}
    errnum_t errnum() { return err_; }
private:
    errnum_t err_;
};

////////////////////////// 错误码 //////////////////////////
constexpr errnum_t OK = 0;
constexpr errnum_t EIO_REG = 50;
constexpr errnum_t EIO_MEM = 60;
constexpr errnum_t EIO_TERM = 100;  //终端IO错误

YABI_END
#endif