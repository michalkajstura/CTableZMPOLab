#include "../../include/arrayUtils.h"

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
