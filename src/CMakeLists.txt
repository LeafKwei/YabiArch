set(BIN_NAME
    yabi
)

set(DBG_NAME
   yabidbg
)

set(COMMON_SRC

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