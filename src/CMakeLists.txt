set(BIN_NAME
    yabi
)

set(DBG_NAME
   yabidbg
)

set(COMMON_SRC
    arch/adu/ADU.cpp
    arch/dcu/DCU.cpp
    arch/ixu/IXU.cpp
    arch/mcu/MCU.cpp
    arch/zeta/YabiMachine.cpp

    io/dev/PeriDeviceIO.cpp
    io/dev/term/TermIO.cpp
    io/mem/MemoryIO.cpp
    io/op/ImmopIO.cpp
    io/op/MemopIO.cpp
    io/op/RegopIO.cpp
    io/reg/RegTableIO.cpp

    kit/MemAgent.cpp
    yabi/yabi.cpp
)

set(SRC
    ${COMMON_SRC}
)

set(DBG_SRC
    ${COMMON_SRC}
)

#头文件目录
include_directories(
    ../include
)

#可执行文件
add_executable(${BIN_NAME}
    ${SRC}
)

#add_executable(${DBG_NAME}
#    ${DBG_SRC}
#)

#编译选项(gcc)
target_compile_options(${BIN_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
)

#target_compile_options(${DBG_NAME}
#    -Wall
#    -Wextra
#    -Wpedantic
#)