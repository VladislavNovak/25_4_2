#include <iostream>
#include "keyboard.h"
#include "utility.h"

void input(Ram &ram) {
    while(true) {
        std::cout << "Enter value: ";
        int value = putInput();
        std::cout << "Enter index: ";
        int index = putInput();

        if (ram.write(value, index)) break;
        std::cout << "Range error. Try again" << std::endl;
    }
}