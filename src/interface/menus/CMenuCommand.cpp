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

string CMenuCommand::getName() {
    return m_name;
}

string CMenuCommand::toString() {
    return " (" + m_commandName + " " + m_command->getArgumentsInfo() + ")";
}

string CMenuCommand::getCommandName() {
    return m_commandName;
}

void CMenuCommand::run(vector<string> arguments) {
    m_command->runCommand(arguments);
}

CCommand* CMenuCommand::getCommand() {
    return m_command;
}