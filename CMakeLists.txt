cmake_minimum_required(VERSION 3.25)
project(25_4_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(25_4_2 main.cpp src/utility.cpp include/utility.h src/keyboard.cpp include/keyboard.h src/ram.cpp include/ram.h src/gpu_display.cpp include/gpu_display.h src/disk.cpp include/disk.h src/cpu.cpp include/cpu.h)
