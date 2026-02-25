#include <unordered_map>
#include "io/UniIO.hpp"
YABI_BEGIN

class RegTableIO : public UniIO{
public:
    RegTableIO();
    void bezero() const noexcept;  //将所有寄存器置0
    int ioid() const noexcept;
    errnum_t ioerr() const noexcept;
    void cleanerr() noexcept;
	regsize_t in(addr_t reg_addr_port, iosize_t n) noexcept;
    void        out(addr_t reg_addr_port, regsize_t data, iosize_t n) noexcept;

private:
    regsize_t dfreg_;
    errnum_t err_;
    std::unordered_map<int, regsize_t> regtable_;

private:
    void initRegtable();
    regsize_t& addr2reg(addr_t addr);
};

YABI_END