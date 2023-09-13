#ifndef INC_25_4_2_RAM_H
#define INC_25_4_2_RAM_H

#include <vector>

struct Ram {
public:
    Ram() : MAX_SIZE(8), memory(MAX_SIZE, 0) {};
    // запись в значения (int) в индекс (int) массива в Ram.memory[]
    bool write(int, int);
    // чтение значения из Ram.memory[] по индексу (int)
    int read(int);
    // общее количество элементов Ram.memory[]
    std::size_t getSize();

private:
    const int MAX_SIZE;
    std::vector<int> memory;
};

#endif //INC_25_4_2_RAM_H
