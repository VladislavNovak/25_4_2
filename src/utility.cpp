#include <iostream>
#include <algorithm>
#include <limits>
#include "utility.h"

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

int selectMenuItem(std::vector<std::string> const &list) {
    while (true) {
        std::cout << (list.size() > 1 ? ("Select one of the options:") : ("Enter the command:"));
        for (const auto &item : list) std::cout << item << (item != list[list.size() - 1] ? "|" : "\n");

        while (true) {
            std::string userInput;
            std::cout << "Type the command:";
            std::getline(std::cin, userInput);

            for (int i = 0; i < list.size(); ++i)
                if (list[i] == userInput) return i;

            std::cout << "Error. Try again!" << std::endl;
        }
    }
}