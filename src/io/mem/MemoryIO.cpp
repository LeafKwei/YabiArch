#include <stdexcept>
#include "def/io/ioid.hpp"
#include "def/config.hpp"
#include "utility/byteorder.hpp"
#include "io/mem/MemoryIO.hpp"
YABI_BEGIN

MemoryIO::MemoryIO()
    : mem_(MEM_INIT_SIZE)
    , err_(OK)
{

}

int MemoryIO::ioid() const noexcept{
    return IOID_MEM;
}

regsize_t MemoryIO::in(memaddr_t addr, iosize_t n){
    try{
        if(addr >= mem_.size()) resizeMem(addr);  //超出内存范围则扩容

        /**
         * 需要说明一点，YabiArch是小端序，因此需要从mem_中从低字节到高字节依次取出每个字节，再使用字节序无关的工具函数setbyte等
         * 将这些字节设置到data中，从而与物理机兼容
         */
        regsize_t data = 0;
        for(iosize_t idx = 0; idx < n; idx++){
            memunit_t mu = mem_.at(addr + idx);
            data = setbyte(data, mu, idx);
        }

        return data;
    }catch(std::exception e){
        throw YabiExcept(EIO_MEM, e.what());
    }
}

void MemoryIO::out(memaddr_t addr, regsize_t data, iosize_t n){
    try{
        if(addr >= mem_.size()) resizeMem(addr);  //超出内存范围则扩容

        /* 取出每个字节，将这些字节从低地址向高地址方向依次保存 */
        for(iosize_t idx = 0; idx < n; idx++){
            memunit_t mu = getbyte(data, idx);
            mem_.at(addr + idx) = mu;
        }
    }catch(std::exception e){
        throw YabiExcept(EIO_MEM, e.what());
    }
}

void MemoryIO::resizeMem(memaddr_t addr){
    mem_.resize(addr + MEM_RESZ_SIZE);
}

YABI_END