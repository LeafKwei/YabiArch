#ifndef YABI_MEMORYIO_HPP
#define YABI_MEMORYIO_HPP

#include <vector>
#include "io/UniIO.hpp"
YABI_BEGIN

class MemoryIO : public UniIO{
public:
    MemoryIO();
    int ioid() const noexcept override;
    errnum_t ioerr() const noexcept override;
    void cleanerr() noexcept override;
	regsize_t in(memaddr_t addr, iosize_t n) noexcept override;
    void out(memaddr_t addr, regsize_t data, iosize_t n) noexcept override;

private:
    errnum_t err_;
    std::vector<memunit_t> mem_;

private:
    void resizeMem(memaddr_t addr);
};

YABI_END
#endif