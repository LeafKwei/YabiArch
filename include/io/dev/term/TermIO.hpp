#ifndef YABI_TERMIO_HPP
#define YABI_TERMIO_HPP

#include "io/RandomIO.hpp"
YABI_BEGIN

/* TermIO提供终端IO功能(标准输入、输出、错误) */
class TermIO : public RandomIO{
public:
    TermIO() =default;
    int ioid() const noexcept;
	qword_t in(memaddr_t port, iosize_t n);
    void        out(memaddr_t port, qword_t data, iosize_t n);

private:
    byte_t in_port_stdin();
    byte_t in_port_stdout();
    byte_t in_port_stderr();
    void out_port_stdin(byte_t ch);
    void out_port_stdout(byte_t ch);
    void out_port_stderr(byte_t ch);
};

YABI_END
#endif