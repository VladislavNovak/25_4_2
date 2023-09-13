cmake_minimum_required(VERSION 3.25)

add_executable(
        25_4_2
        main.cpp
        ${CMAKE_SOURCE_DIR}/include/utility.h utility.cpp
        ${CMAKE_SOURCE_DIR}/include/keyboard.h keyboard.cpp
        ${CMAKE_SOURCE_DIR}/include/ram.h ram.cpp
        ${CMAKE_SOURCE_DIR}/include/gpu_display.h gpu_display.cpp
        ${CMAKE_SOURCE_DIR}/include/disk.h disk.cpp
        ${CMAKE_SOURCE_DIR}/include/cpu.h cpu.cpp
)

target_include_directories(25_4_2 PUBLIC ${CMAKE_SOURCE_DIR}/include)
