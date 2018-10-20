#include "../../../include/CMenuCommand.h"

using namespace std;

const string DEFAULT_NAME = "Komenda domyślna";

CMenuCommand::CMenuCommand(CCommand *command, string commandName, string name=DEFAULT_NAME) {
    m_command = command;
    m_commandName = commandName;
    m_name = name;
}

CMenuCommand::~CMenuCommand(){
    delete m_command;
}

std::string CMenuCommand::getName() {
    return m_name;
}

std::string CMenuCommand::getCommandName() {
    return m_commandName;
}

void CMenuCommand::run() {
    m_command->runCommand();
}