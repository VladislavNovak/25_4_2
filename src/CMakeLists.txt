cmake_minimum_required(VERSION 3.25)

add_executable(
        25_4_2
        main.cpp
        utility.cpp
        ram.cpp
        keyboard.cpp
        gpu_display.cpp
        disk.cpp
        cpu.cpp
)

target_include_directories(25_4_2 PUBLIC ${CMAKE_SOURCE_DIR}/include)
