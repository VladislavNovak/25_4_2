#include <iostream>
#include "../include/ram.h"
#include "../include/keyboard.h"
#include "../include/gpu_display.h"
#include "../include/disk.h"
#include "../include/cpu.h"

int main() {
    Ram ram;
    Ram ram2;
    ram.write(10, 0);
    ram.write(3, 1);
    ram.write(4, 2);

    display(ram);

    input(ram);

    ram.write(8, 6);

    display(ram);

    auto summa = sum(ram);

    std::cout << "sum is: " << summa << std::endl;

    const char* path = R"(..\test.txt)";

    save(path, ram);

    load(path, ram2);

    std::cout << "New data: " << std::endl;

    display(ram2);

    return 0;
}
