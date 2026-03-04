#include <iostream>
#include "def/err.hpp"
#include "def/port.hpp"
#include "io/dev/term/TermIO.hpp"
YABI_BEGIN

int TermIO::ioid() const noexcept{
    return 0;
}

qword_t TermIO::in(memaddr_t port, iosize_t n){
    switch(port){
        case PORT_TERM_IN:
            return in_port_stdin();
        case PORT_TERM_OUT:
            return in_port_stdout();
        case PORT_TERM_ERR:
            return in_port_stderr();
    }
}

void TermIO::out(memaddr_t port, qword_t data, iosize_t n){
    switch(port){
        case PORT_TERM_IN:
            out_port_stdin(static_cast<byte_t>(data));
        case PORT_TERM_OUT:
            out_port_stdout(static_cast<byte_t>(data));
        case PORT_TERM_ERR:
            out_port_stderr(static_cast<byte_t>(data));
    }
}

byte_t TermIO::in_port_stdin(){ return static_cast<byte_t>(std::cin.get()); }
byte_t TermIO::in_port_stdout(){ return 0; }
byte_t TermIO::in_port_stderr(){ return 0; }
void TermIO::out_port_stdin(byte_t ch){ return; }
void TermIO::out_port_stdout(byte_t ch){ std::cout << ch; }
void TermIO::out_port_stderr(byte_t ch){ std::cerr << ch; }

YABI_END