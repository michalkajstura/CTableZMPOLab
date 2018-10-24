#include "commands/CAddNewCommand.h"

using namespace std;

CAddNewCommand::CAddNewCommand(CMenu *menu) : CProgramStructureCommand(menu) {
    m_arguments_info = "<command name> <name>";
    m_arguments_number = 2;
}

void CAddNewCommand::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string commandName = arguments.at(0);
    string name = arguments.at(1);
    if (!validateCommandName(commandName)) return;
    m_menu->addMenuItem(new CMenuCommand(new CCommand, commandName, name));

}
