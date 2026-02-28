#ifndef YABI_MEMORYIO_HPP
#define YABI_MEMORYIO_HPP

#include <vector>
#include "io/RandomIO.hpp"
YABI_BEGIN

class MemoryIO : public RandomIO{
public:
    MemoryIO();
    int ioid() const noexcept override;
	qword_t in(memaddr_t addr, iosize_t n) override;
    void out(memaddr_t addr, qword_t data, iosize_t n) override;

private:
    std::vector<memunit_t> mem_;

private:
    void resizeMem(memaddr_t addr);
};

YABI_END
#endif