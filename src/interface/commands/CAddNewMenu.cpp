#include "commands/CAddNewMenu.h"

using namespace std;

const string COMMAND_ALREADY_EXIST = "Komenda o podanej nazwie już istnieje";

CAddNewMenu::CAddNewMenu(CMenu *menu) : CProgramStructureCommand(menu) {
    m_arguments_info = "<command name> <menu name>";
    m_arguments_number = 2;
}

void CAddNewMenu::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string newCommandName = arguments.at(0);
    string newMenuName = arguments.at(1);
    // Check if there is no other command with this name
    if (!validateCommandName(newCommandName)) return;
    m_menu->addMenuItem(new CMenu(newCommandName, newMenuName));
}

bool CAddNewMenu::validateCommandName(std::string commandName) {
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
