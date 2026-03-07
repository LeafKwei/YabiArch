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
constexpr errnum_t Good = 0;
constexpr errnum_t ERRADMOD = 1;     //错误的寻址模式
constexpr errnum_t ERROPCODE = 2;     //错误的指令编码
constexpr errnum_t ERRDCU= 3;            //解码出错
constexpr errnum_t ERRADU = 4;           //寻址出错
constexpr errnum_t ERRIXU = 5;             //执行出错
constexpr errnum_t ERRMCU = 6;          //控制出错

constexpr errnum_t ERRIOREG = 50;        //寄存器IO错误
constexpr errnum_t ERRIOMEM = 51;      //内存IO错误
constexpr errnum_t ERRIODEV = 52;        //设备IO错误
constexpr errnum_t ERRIOPORT = 53;      //错误的IO端口

constexpr errnum_t ERRUNSUP = 130;     //不支持的操作

constexpr errnum_t ERRRANGE = 150;     //错误的范围

YABI_END
#endif