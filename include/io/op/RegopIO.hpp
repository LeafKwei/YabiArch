#ifndef YABI_REGOPIO_HPP
#define YABI_REGOPIO_HPP

#include "io/OrderedIO.hpp"
YABI_BEGIN

class RegTableIO;

class RegopIO : public OrderedIO{
public:
    RegopIO() =default;
    void setReg(RegTableIO *rtb, memaddr_t reg, iosize_t size);
	int ioid() const noexcept override;
    memaddr_t addr() const noexcept override;
    iosize_t size() const noexcept override;
    void moveup() noexcept override;
    void movedown() noexcept override;
	qword_t in() override;                                 
    void        out(qword_t data) override;

private:
    RegTableIO *rtb_;
    memaddr_t reg_;
    iosize_t size_;
};

YABI_END
#endif