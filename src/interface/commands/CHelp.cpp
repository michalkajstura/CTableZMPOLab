#include "commands/CHelp.h"

using namespace std;

const string COMMAND_NOT_IN_LIST = "Nie ma takiej komendy";

CHelp::CHelp(vector<CMenuItem*> &commands){
    m_arguments_number = 1;
    m_arguments_info = "<command name>";
    m_commands = &commands;
}

CMenuCommand *CHelp::findCommand(std::string commandName) {
    for (int i=0; i<m_commands->size(); i++) {
        if (m_commands->at(i)->getCommandName() == commandName) {
            CMenuItem *item = m_commands->at(i);
            return dynamic_cast<CMenuCommand*>(item);
        }
    }
    return NULL;
}

void CHelp::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string commandName = arguments.at(0);
    CMenuCommand *command = findCommand(commandName);
    if (command == NULL)
        cout << COMMAND_NOT_IN_LIST << endl;
    else {
        cout << command->getCommand()->getHelp() << endl;
    }


}


