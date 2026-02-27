#ifndef YABI_MEMORYIO_HPP
#define YABI_MEMORYIO_HPP

#include <vector>
#include "io/RandIO.hpp"
YABI_BEGIN

class MemoryIO : public RandIO{
public:
    MemoryIO();
    int ioid() const noexcept override;
	regunit_t in(memaddr_t addr, iosize_t n) override;
    void out(memaddr_t addr, regunit_t data, iosize_t n) override;

private:
    std::vector<memunit_t> mem_;

private:
    void resizeMem(memaddr_t addr);
};

YABI_END
#endif