//
// Created by michal on 05.10.18.
//

#ifndef CTABLE_ARRAYUTILS_H
#define CTABLE_ARRAYUTILS_H

#include <iostream>
#include <vector>
#include <string>

namespace arrayUtils {
    void fillArray(int fromIndex, int toIndex, int value, int *array);
    void copyArray(int *source, int *dest, int numberOfElements);
}

namespace stringUtils {
    bool isInt(std::string str);
    std::vector<std::string> splitString(std::string userInput);
}

namespace inputUtils {
    void waitForUser();
}
#endif //CTABLE_ARRAYUTILS_H
