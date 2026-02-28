#ifndef YABI_REGOPIO_HPP
#define YABI_REGOPIO_HPP

#include "io/OrderedIO.hpp"
YABI_BEGIN

class RegTableIO;

class MemopIO : public OrderedIO{
public:
    MemopIO(RegTableIO *rtb, memaddr_t reg, iosize_t size);
	int ioid() const noexcept override;             
    memaddr_t addr() const noexcept override;  
    iosize_t size() const noexcept override;
    void moveup() noexcept override;              
    void movedown() noexcept override;         
	regunit_t in() override;                                 
    void        out(regunit_t data) override;

private:
    RegTableIO *rtb;
    memaddr_t reg_;
    iosize_t size_;
};

YABI_END
#endif