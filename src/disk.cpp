#include <iostream>
#include <vector>
#include <fstream>
#include "../include/disk.h"
#include "../include/utility.h"

// модуль disk
void save(const char* path, Ram &ram) {
    std::ofstream file(path, std::ios::out);

    for (int i = 0; i < ram.getSize(); ++i) {
        file << ram.read(i) << std::endl;
    }
}

// модуль disk
void load(const char* path, Ram &ram) {
    std::ifstream file(path);
    std::vector<int> data;

    if (file.is_open() && !file.bad()) {
        std::string current;
        while(std::getline(file, current)) {
            if (isNumeric(current)) {
                data.emplace_back(std::stoi(current));
            }
        }

        for (auto i = 0; i < ram.getSize() && i < data.size(); ++i) {
            int value = (i < data.size()) ? data[i] : 0;
            ram.write(value, i);
        }
    }
}
