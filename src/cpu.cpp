#include "cpu.h"

int sum(Ram &ram) {
    int acc = 0;
    for (int i = 0; i < ram.getSize(); ++i) {
        if (ram.read(i) != 0) acc += ram.read(i);
    }

    return acc;
}
