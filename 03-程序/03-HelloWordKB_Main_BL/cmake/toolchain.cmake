set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER_FORCED 1)
set(CMAKE_CXX_COMPILER_FORCED 1)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)

add_compile_options(
    -Os -ggdb -std=c11 -Wall -pedantic -Werror
    -ffunction-sections -fdata-sections -Wno-overlength-strings
    -mcpu=cortex-m3 -mthumb -DSTM32F1 -fno-builtin-memcpy
    -pedantic -flto
)

add_link_options(
    -ggdb -ffunction-sections -fdata-sections
    -nostartfiles -lc -lnosys
    -mthumb -mcpu=cortex-m3 -Wl,-gc-sections -flto
    -Wl,--print-memory-usage
    -Wl,-Map,bootloader-dfu-fw.map
)
