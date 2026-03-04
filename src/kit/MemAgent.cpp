#include "def/reg.hpp"
#include "kit/MemAgent.hpp"
#include "io/reg/RegTableIO.hpp"
#include "io/mem/MemoryIO.hpp"
YABI_BEGIN

MemAgent::MemAgent(RegTableIO *rtb, MemoryIO *mem)
    : rtb_(rtb)
    , mem_(mem)
{

}

qword_t MemAgent::in(iosize_t n){
    std::cout << "111" << std::endl;
    auto qip = rtb_ -> in(QIP, sizeof(qword_t));
    std::cout << "222" << std::endl;
    auto data = mem_ -> in(qip, n);
    std::cout << "333" << std::endl;
    qip_ = qip;   //保留当前的QIP值以便后续能够恢复
    qip += n;     //更新QIP值并写入到rtb
    rtb_ -> out(QIP, qip, sizeof(qword_t));
    std::cout << "444" << std::endl;
    return data;
}

void MemAgent::undo(){
    rtb_ -> out(QIP, qip_, sizeof(qword_t));
}

MemoryIO* MemAgent::memory(){
    return mem_;
}

YABI_END