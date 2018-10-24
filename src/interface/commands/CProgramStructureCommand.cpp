#include "commands/CProgramStructureCommand.h"

using namespace std;

const string COMMAND_ALREADY_EXIST = "Komenda o podanej nazwie już istnieje";

CProgramStructureCommand::CProgramStructureCommand(CMenu *menu) {
    m_menu = menu;
}

bool CProgramStructureCommand::validateCommandName(std::string commandName) {
    vector<CMenuItem*> *commands = m_menu->getCommands();
    vector<CMenuItem*>::iterator iter = commands->begin();
    for (iter; iter != commands->end(); iter++) {
        if ((*iter)->getCommandName() == commandName) {
            cout << COMMAND_ALREADY_EXIST << endl;
            return false;
        }
    }
    return true;
}