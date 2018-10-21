#include <iostream>
#include "../../../include/CCommand.h"

using namespace std;

void CCommand::runCommand(vector<string> arguments) {
    cout << "Komenda domyślna" << endl;
}

std::string CCommand::getArgumentsInfo() {
    return m_arguments_info;
}

bool CCommand::validaterNumberOfArguments(int numberOfArguments) {
    if (numberOfArguments != m_arguments_number) {
        cout << INVALID_NUMBER_OF_ARGUMENTS << endl;
        return false;
    } else {
        return true;
    }
}