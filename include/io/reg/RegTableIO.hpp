#include <vector>
#include "io/RandIO.hpp"
YABI_BEGIN

class RegTableIO : public RandIO{
public:
    RegTableIO();
    void bezero() noexcept;  //将所有寄存器置0
    int ioid() const noexcept;
    errnum_t ioerr() const noexcept;
    void cleanerr() noexcept;
	regsize_t in(memaddr_t reg_addr_port, iosize_t n) noexcept;  //寄存器IO强制按寄存器大小进行，因此参数n在此处无效
    void        out(memaddr_t reg_addr_port, regsize_t data, iosize_t n) noexcept;

private:
    errnum_t err_;
    std::vector<regsize_t> regtable_;   //初始化64个元素作为寄存器
};

YABI_END