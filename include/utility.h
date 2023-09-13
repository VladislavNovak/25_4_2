#ifndef INC_25_4_2_UTILITY_H
#define INC_25_4_2_UTILITY_H

#include <vector>

// true если символ или группа символов является числом
bool isNumeric(const std::string &);
// пользовательский ввод
int putInput();
// оптимизирует меню
int selectMenuItem(std::vector<std::string> const &);

#endif //INC_25_4_2_UTILITY_H

