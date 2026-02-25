set(BIN_NAME
    yabi
)

set(DBG_NAME
   yabidbg
)

set(COMMON_SRC
    src/io/mem/MemoryIO.cpp
    src/io/reg/RegTableIO.cpp
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

add_executable${DBG_NAME}
    ${DBG_SRC}
)