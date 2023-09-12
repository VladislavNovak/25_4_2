#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>

bool isNumeric(std::string const &str) {
    auto it = std::find_if(str.begin(), str.end(), [](const char &c) { return !std::isdigit(c); });

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

struct Ram {
public:
    Ram() : MAX_SIZE(8), memory(MAX_SIZE, 0) {};

    bool write(int value, int index) {
        if (index < 0 || index >= MAX_SIZE) return false;

        return (memory[index] = value);
    };

    int read(int index) {
        return (index >= 0 && index < MAX_SIZE) ? memory[index] : 0;
    }

    size_t getSize() {
        return memory.size();
    }

private:
    const int MAX_SIZE;
    std::vector<int> memory;
};

int sum(Ram &ram) {
    int acc = 0;
    for (int i = 0; i < ram.getSize(); ++i) {
        if (ram.read(i) != 0) acc += ram.read(i);
    }

    return acc;
}

// модуль gpu
void display(Ram &ram) {
    for (int i = 0; i < ram.getSize(); ++i) {
        std::cout << "item (" << i << "): " << ram.read(i) << std::endl;
    }
}

// модуль kbd
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
