#include <iostream>
#include <fstream>
#include "arch/YabiMachine.hpp"

int main(int argc, char *argv[]){
    /* 检查参数 */
    if(argc < 2){
        std::cerr << "No file provided." << std::endl;
        return 1;
    }

    /* 打开文件 */
    std::ifstream ifs(argv[1]);
    if(!ifs.is_open()){
        std::cerr << "Failed to open " << argv[1] << std::endl;
        return 1;
    }

    /* 获取文件大小 */
    ifs.seekg(0, std::ios::end);
    auto filesize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    
    /* 创建对应大小的缓冲区并读取文件 */
    std::vector<char> buffer(filesize);
    ifs.read(buffer.data(), filesize);
    if(!ifs.good()){
        std::cerr << "Failed to read " << argv[1] << std::endl;
        return 1;
    }

    /* 加载二进制文件到地址0并执行 */
    yabi::YabiMachine machine;
    machine.load(reinterpret_cast<yabi::ubyte_t*>(buffer.data()), filesize, 0);
    machine.setEntry(0);
    machine.start();
}