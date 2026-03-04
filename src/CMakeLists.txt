set(BIN_NAME
    yabi
)

set(DBG_NAME
   yabidbg
)

set(COMMON_SRC
    arch/YabiMachine.cpp
    arch/adu/ADU.cpp
    arch/dcu/DCU.cpp
    arch/ixu/IXU.cpp
    arch/mcu/MCU.cpp

    io/dev/PeriDeviceIO.cpp
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

include_directories(
    ../include
)

add_executable(${BIN_NAME}
    ${SRC}
)

#add_executable(${DBG_NAME}
#    ${DBG_SRC}
#)