#include <stdexcept>
#include "def/ioid.hpp"
#include "def/config.hpp"
#include "utility/byte.hpp"
#include "io/mem/MemoryIO.hpp"
YABI_BEGIN

MemoryIO::MemoryIO() : mem_(MEM_INIT_SIZE){

}

int MemoryIO::ioid() const noexcept{
    return IOID_MEM;
}

qword_t MemoryIO::in(memaddr_t addr, iosize_t n){
    try{
        if(addr >= mem_.size()) resizeMem(addr);  //超出内存范围则扩容

        /* 从Memory中读出指定数量的字节并设置到data中  */
        qword_t data = 0;
        for(iosize_t idx = 0; idx < n; idx++){
            memunit_t mu = mem_.at(addr + idx);
            data = setbyte(0, mu, idx);
        }

        return data;
    }catch(std::exception &e){
        throw YabiExcept(ERRIOMEM, e.what());
    }
}

void MemoryIO::out(memaddr_t addr, qword_t data, iosize_t n){
    try{
        if(addr >= mem_.size()) resizeMem(addr);  //超出内存范围则扩容

        /* 取出每个字节，将这些字节从低地址向高地址方向依次保存 */
        for(iosize_t idx = 0; idx < n; idx++){
            memunit_t mu = getbyte(data , idx);
            mem_.at(addr + idx) = mu;
        }
    }catch(std::exception &e){
        throw YabiExcept(ERRIOMEM, e.what());
    }
}

void MemoryIO::resizeMem(memaddr_t addr){
    mem_.resize(addr + MEM_RESZ_SIZE);
}

YABI_END