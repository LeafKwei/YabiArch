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



### 操作码编码结构

#### 基本原理

虚拟机每次读取当前rip指向的首个字节，根据上述结构解析该字节的操作码和指令长度到InstStruct中，随后，根据`指令编号`部分从指令集中获取指令，接着调用该指令的rfunc函数从内存读取操作数。



#### 指令结构

指令分为短指令和长指令，短指令不依赖任何操作数，长指令需要依赖操作数：

* 短指令(1字节)

```
|---长指令标志(1bit)---|----操作码(7bit)---|
|________________8bit___________________|
```

* 长指令(2字节)

```
|-1(1bit)-|---------操作码(7bit)---------||--操作数组合(4bit)--|-操作数a长度(2bit)-|-操作数b长度(2bit)-|
|________________8bit___________________||_______________________8bit____________________________|
```

操作数组合(src,dst)：立即数、寄存器、(立即数，寄存器)、(寄存器、寄存器)、(内存、寄存器)、(寄存器、内存)

操作数长度：1字节(00b)、2字节(01b，word)、4字节(10b，dword)、8字节(11b，qword)

寻址方式：立即数寻址、寄存器寻址、存储器寻址

存储器寻址方式：直接寻址(以立即数作地址)、间接寻址(以寄存器作地址)



#### 指令解析与执行流程

读取1字节--->是否存在长指令标志

---否--->修改rip--->获取操作码后调用ifunc执行指令

---是--->读取1字节--->解析长指令--->调用rfunc读取操作数--->修改rip--->调用ifunc执行指令



#### 中断

InstStruct指令结构如下：

```c++
struct InstStruct{
    bool lflag; //长指令标志
	opcode_t opcode; //操作码
    unsigned char opcomb; //操作数组合
    unsigned char opsize1; //操作数1长度
    unsigned char opsize2; //操作数2长度
    regsize_t op1;  //操作数1
    regsize_t op2;  //操作数2
    intcode_t intcode; //中断码
};
```

每次取指令前，虚拟机必须将InstStruct置0；当一条指令的处理函数返回时，需要检查intcode是否为0，如果不为0则触发中断处理程序，并且应该像物理机器那样调用虚拟机内存中的中断处理程序(触发前可像物理机器那样进行现场保护工作)。
