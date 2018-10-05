#include "../../include/utils.h"

using namespace std;

namespace arrayUtils {
    void fillArray(int fromIndex, int toIndex, int value, int *array) {
        for (int i = fromIndex; i < toIndex; i++) {
            array[i] = value;
        }
    }

    void copyArray(int *source, int *destination, int numberOfElements) {
        for (int i = 0; i < numberOfElements; i++) {
            destination[i] = source[i];
        }
    }
}

namespace stringUtils {
    bool isInt(string str) {
        // check whether string can be parsed into integer
        string::iterator iterator = str.begin();
        while(iterator != str.end() && isdigit(*iterator)) ++iterator;
        return !str.empty() && iterator == str.end();
    }
}

