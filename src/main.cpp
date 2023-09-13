#include <iostream>
#include <vector>
#include <string>
#include "ram.h"
#include "keyboard.h"
#include "gpu_display.h"
#include "disk.h"
#include "cpu.h"
#include "utility.h"

int main() {
    bool isProcess = true;
    const char* path = R"(..\test.txt)";
    std::vector<std::string> menuList = {"sum", "save", "load", "input", "display", "exit" };
    Ram ramData;

    while(isProcess) {
        auto result = selectMenuItem(menuList);

        switch (result) {
            case 0:
                std::cout << "Summation: " << sum(ramData) << std::endl;
                break;
            case 1:
                std::cout << "(Saving mode)" << std::endl;
                save(path, ramData);
                break;
            case 2:
                std::cout << "(Loading mode)" << std::endl;
                load(path, ramData);
                break;
            case 3:
                std::cout << "(Entry mode)" << std::endl;
                input(ramData);
                break;
            case 4:
                std::cout << "(Show mode)" << std::endl;
                display(ramData);
                break;
            case 5:
            default:
                std::cout << "Exit" << std::endl;
                isProcess = false;
        }
    }

    return 0;
}
