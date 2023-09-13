#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "../include/utility.h"

bool isNumeric(const std::string &str) {
    auto it = std::find_if(
            str.begin(),
            str.end(),
            [](const char &c) { return !std::isdigit(c); });

    return (!str.empty() && it == str.end());
}

int putInput() {
    int input;

    while (true) {
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input is invalid. Please try again: ";
            continue;
        }

        break;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input;
}