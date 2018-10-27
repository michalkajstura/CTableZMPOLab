#include "commands/CAddNewMenu.h"

using namespace std;

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
