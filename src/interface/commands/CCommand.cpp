#include <iostream>
#include "commands/CCommand.h"

using namespace std;

CCommand::CCommand() {
    m_help_info = "";
}

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

std::string CCommand::getHelp() {
    return m_help_info;
}

void CCommand::setHelp(string help) {
    m_help_info =  help;
}