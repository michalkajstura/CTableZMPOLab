#include "../../../include/CMenuItem.h"
#include <string>

using namespace std;

CMenuItem::~CMenuItem() {}

string CMenuItem::loadString(std::string bigString, int *index) {
    string buffer = "";
    bool stop = false;
    // Don't read and semicolon
    (*index)++;
    while (*index < bigString.length() && !stop) {
        char charAt = bigString.at(*index);
        if (charAt == '\'')
            stop = true;
        else
            buffer += charAt;
        (*index)++;
    }
    return buffer;
}
