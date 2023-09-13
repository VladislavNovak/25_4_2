#include <iostream>
#include "gpu_display.h"

void display(Ram &ram) {
    for (int i = 0; i < ram.getSize(); ++i) {
        std::cout << "item (" << i << "): " << ram.read(i) << std::endl;
    }
}
