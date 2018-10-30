#include <vector>
#include "../../include/utils.h"

using namespace std;

const string PRESS_ENTER = "Naciśnij enter by kontynuować";

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

    vector<string> splitString(string userInput) {
        // Split user input by spaces
        string buffer;
        vector<string> bufferList;
        for(int i=0; i<userInput.size(); i++) {

            // If it's a space add to buffer
            if (userInput.at(i) == ' ') {
                bufferList.push_back(buffer);
                buffer.clear();
            }

                // Else append char to buffer
            else {
                buffer += userInput.at(i);
            }
        }
        if (buffer != "")
            bufferList.push_back(buffer);

        return bufferList;
    }
}

namespace inputUtils {
    void waitForUser() {
        cin.ignore();
        do
        {
            cout << '\n' << PRESS_ENTER;
        } while (cin.get() != '\n');
    }
}


