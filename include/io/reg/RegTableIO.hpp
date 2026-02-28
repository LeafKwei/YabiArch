#include <vector>
#include "io/RandomIO.hpp"
YABI_BEGIN

class RegTableIO : public RandomIO{
public:
    RegTableIO();
    void bezero() noexcept;  //将所有寄存器置0
    int ioid() const noexcept override;
	qword_t in(memaddr_t reg_addr_port, iosize_t n) override;  //寄存器IO强制按寄存器大小进行，因此参数n在此处无效
    void        out(memaddr_t reg_addr_port, qword_t data, iosize_t n) override;

private:
    std::vector<qword_t> regtable_;   //初始化64个元素作为寄存器
};

YABI_END