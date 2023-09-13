#include "ram.h"

bool Ram::write(int value, int index) {
    if (index < 0 || index >= MAX_SIZE) return false;

    return (memory[index] = value);
};

int Ram::read(int index) {
    return (index >= 0 && index < MAX_SIZE) ? memory[index] : 0;
}

std::size_t Ram::getSize() {
    return memory.size();
}
