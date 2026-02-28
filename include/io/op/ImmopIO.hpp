#ifndef YABI_IMMOPIO_HPP
#define YABI_IMMOPIO_HPP

#include "io/OrderedIO.hpp"
YABI_BEGIN

class ImmopIO : public OrderedIO{
public:
    ImmopIO(regunit_t imm, iosize_t size);
	int ioid() const noexcept override;
    memaddr_t addr() const noexcept override;
    iosize_t size() const noexcept override;
    void moveup() noexcept override;
    void movedown() noexcept override;
	regunit_t in() override;
    void        out(regunit_t data) override;

private:
    regunit_t imm_;
    iosize_t   size_;
};

YABI_END
#endif
