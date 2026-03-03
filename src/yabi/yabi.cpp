#include "arch/YabiMachine.hpp"

int main(void){
    yabi::YabiMachine machine;

    yabi::byte_t b = 0b00000000;
    machine.load(&b, 1, 0);
    machine.setEntry(0);
    machine.start();
}