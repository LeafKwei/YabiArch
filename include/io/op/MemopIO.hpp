#ifndef YABI_MEMOPIO_HPP
#define YABI_MEMOPIO_HPP

#include "io/OrderedIO.hpp"
YABI_BEGIN

class MemoryIO;

class MemopIO : public OrderedIO{
public:
    MemopIO(MemoryIO *mem, memaddr_t addr, iosize_t size);
	int ioid() const noexcept override;             
    memaddr_t addr() const noexcept override;  
    iosize_t size() const noexcept override;
    void moveup() noexcept override;              
    void movedown() noexcept override;         
	regunit_t in() override;                                 
    void        out(regunit_t data) override;

private:
    MemoryIO *mem_;
    memaddr_t addr_;
    iosize_t size_;
};

YABI_END
#endif