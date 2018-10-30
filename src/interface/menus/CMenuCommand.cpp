#include "../../../include/CMenuCommand.h"

using namespace std;

const string DEFAULT_NAME = "Komenda domyślna";
const int COMMAND_FIELDS_NUMBER = 3;

CMenuCommand::CMenuCommand() {
}

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

std::string CMenuCommand::save() {
    string stringCommand = "['" + getName() + "','" + getCommandName() +
            "','" + getCommand()->getHelp() + "']";
    return stringCommand;
}

bool CMenuCommand::load(std::string stringMenu, int *index) {
    vector<string> commandItems;
    int numberOfItems = 0;
    bool stop = false;
    // Don't read square parenthesis
    (*index)++;
    while (*index < stringMenu.length() && !stop) {
        char charAt = stringMenu.at(*index);
        if (charAt == '\'' || numberOfItems == 0) {
            commandItems.push_back(loadString(stringMenu, index));
            numberOfItems++;
        } else if (charAt == ',')
            (*index)++;
        else if (charAt == ']') {
            (*index)++;
            stop = true;
        } else { // If it is not first the item then it should have a semicolon
            cerr << EXPECTED_COMMA + INSTEAD + charAt + " at " + to_string(*index)<< endl;
            return false;
        }
    }
    if (commandItems.size() == COMMAND_FIELDS_NUMBER) {
        CCommand *newCommand = new CCommand;
        newCommand->setHelp(commandItems.at(2));
        m_command = newCommand;
        m_commandName = commandItems.at(0);
        m_name = commandItems.at(1);
        return true;
    } else {
        cerr << INVALID_NUMBER_OF_ARGUMENTS + " at " + to_string(*index)<< endl;
        return false;
    }
}
