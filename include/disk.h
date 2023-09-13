#ifndef INC_25_4_2_DISK_H
#define INC_25_4_2_DISK_H

#include "ram.h"

// Позволяет сохранить данные Ram.memory[] на жёсткий диск
void save(const char*, Ram &);

// Позволяет извлечь сохраненные на жёсткий диск данные в оперативную память (Ram.memory[])
void load(const char*, Ram &);

#endif //INC_25_4_2_DISK_H
