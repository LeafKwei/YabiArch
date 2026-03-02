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
    auto qip = rtb_ -> in(QIP, sizeof(maxword_t));
    auto data = mem_ -> in(qip, n);
    qip_ = qip;
    qip += n;
    rtb_ -> out(QIP, qip, sizeof(maxword_t));
}

void MemAgent::undo(){
    rtb_ -> out(QIP, qip_, sizeof(qword_t));
}

YABI_END