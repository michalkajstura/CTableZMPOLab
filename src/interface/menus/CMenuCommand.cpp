#include "../../../include/CMenuCommand.h"

using namespace std;

const string DEFAULT_NAME = "Komenda domyślna";

CMenuCommand::CMenuCommand(CCommand &command, string commandName, string name=DEFAULT_NAME) {
    m_command = &command;
    m_commandName = commandName;
    m_name = name;
}

std::string CMenuCommand::getName() {
    return m_name;
}

std::string CMenuCommand::getCommandName() {
    return m_commandName;
}

void CMenuCommand::assignCommand(CCommand *command) {
    m_command = command;
}

void CMenuCommand::run() {
    m_command->runCommand();
}


