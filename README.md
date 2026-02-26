### 机器模型(小端，little-endian)

* 内存
* 寄存器
* 指令集
* IO设备



### 指令注册函数

registerInstruction函数负责向指令集中注册指令：

```c++
void registerInstruction(
	opcode_t opcode,      //操作码
    std::function<int(
        regsize_t rip, 
        Memory *mem, 
        InstStruct *istruct)> rfunc, //InstStruct对象构造函数
    std::function<void(
        RegTableIO *rtb, 
        PerideviceIO *dev, 
        MemoryIO *mem, 
        InstStruct *istruct) ifunc> //指令处理程序
);

rfunc: InstStruct构造函数，从mem[rip+1]的位置开始，根据InstStruct中的操作码长度从内存中读取操作数到前者中，返回读取的字节数    量以便虚拟机可更新rip
ifunc: 指令处理函数

rtb: 寄存器表
dev: 外部设备访问器
mem: 内存访问器
istruct: 指令结构体(二进制序列化的指令需要先经过解码，转换为结构化的指令结构体InstStruct)
```

RegTable、Peridevice、Memory三者都应该继承自接口UniIO：

```c++
class UniIO{
	int ioid() const noexcept =0;
    Errno     ioerr() const noexcept =0;
	regsize_t in(regsize_t reg_addr_port, size_t n) noexcept =0;
    void out(regsize_t reg_addr_port, regsize_t data, size_t n) noexcept =0;
};
```



### 指令编码结构

```
mov [bx+si*4+imm], qax
mov qax, [bx + si*4 + imm]

模式指示(2bit)
指令操作码(6bit)
寄存器编号(6bit)
寻址方式(4+4bit)
寻址专用寄存器编号(2bit)
操作数宽度(2bit)
立即数(8bit、16bit、32bit、64bit)

基本格式：
  [模式指示(2bit)][指令操作码6bit]
0|______________8bit_____________|   

模式00：极简指令，无操作数
  [00(2bit)][指令操作码6bit]
0|______________8bit_____________|   


模式01：简单指令，32位操作数
  [01(2bit)][指令操作码6bit]
0|______________8bit_____________|   

模式10：复杂指令，后有一个控制字节
  [10(2bit)][指令操作码6bit]            [操作数宽度(2bit)]   [寻址方式1[3bit]]    [寻址方式2[3bit]]
0|______________8bit_____________|   |_______________________________8bit_________________________________|
```



#### 

