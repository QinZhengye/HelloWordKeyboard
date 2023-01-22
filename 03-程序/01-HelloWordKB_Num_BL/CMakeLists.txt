cmake_minimum_required(VERSION 3.10)
include(cmake/toolchain.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HelloWordKB-Num-BL)

set(FLASH_BASE_ADDR 0x08000000)
set(FLASH_SIZE_KB 128)
set(FLASH_BOOTLDR_SIZE_KB 8)

include(cmake/boards.cmake)

if(BOARD_SRCS)
    list(
        TRANSFORM BOARD_SRCS
        PREPEND "${BOARD_DIR}/"
    )
endif()

add_executable(
    ${PROJECT_NAME}
    src/init.c
    src/main.c
    src/usb.c
    ${BOARD_SRCS}
        boards/helloword/keyboard.c)

if(BOARD_DEFS)
    target_compile_definitions(
        ${PROJECT_NAME} PRIVATE ${BOARD_DEFS}
    )
endif()

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_options(
    ${PROJECT_NAME} PRIVATE
    -Wl,-T${PROJECT_SOURCE_DIR}/stm32f103.ld
    -Wl,-Ttext=${FLASH_BASE_ADDR}
)

math(
    EXPR
    FLASH_BOOTLDR_PAYLOAD_SIZE_KB
    "${FLASH_SIZE_KB} - ${FLASH_BOOTLDR_SIZE_KB}"
)

target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    FLASH_BASE_ADDR=${FLASH_BASE_ADDR}
    FLASH_SIZE_KB=${FLASH_SIZE_KB}
    FLASH_BOOTLDR_SIZE_KB=${FLASH_BOOTLDR_SIZE_KB}
    FLASH_BOOTLDR_PAYLOAD_SIZE_KB=${FLASH_BOOTLDR_PAYLOAD_SIZE_KB}
)

execute_process(
    COMMAND
    git describe --abbrev=8 --dirty --always --tags
    OUTPUT_VARIABLE GIT_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    VERSION="${GIT_VERSION}"
)

set(CMAKE_EXECUTABLE_SUFFIX .elf)

add_custom_target(
    build_bin ALL
    DEPENDS ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.elf
    COMMAND ${CMAKE_OBJCOPY} -O binary
        ${PROJECT_NAME}.elf
        ${PROJECT_NAME}.bin
)

add_custom_target(
    build_hex ALL
    DEPENDS ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.elf
    COMMAND ${CMAKE_OBJCOPY} -O ihex
        ${PROJECT_NAME}.elf
        ${PROJECT_NAME}.hex
)
