#include "../../../include/CMenu.h"
#include "utils.h"

using namespace std;

const int COMMAND_NOT_IN_LIST = -1;
const string INVALID_COMMAND = "Niepoprawna komenda";
const string DEFAULT_NAME = "Menu domyślne";


CMenu::CMenu(std::string commandName, std::string name=DEFAULT_NAME) {
    m_name = name;
    m_commandName = commandName;
    m_nextIter = true;
}

CMenu::~CMenu() {

}

void CMenu::run() {
    while(m_nextIter) {
        showName();
        showCommands();
        string userInput = getUserInput();
        if (checkQuitLoop(userInput)) {
            m_nextIter = false;
        } else {
            int commandIndex = validateUserInput(userInput);
            matchCommand(commandIndex);
        }
    }
}

void CMenu::showName() {
    cout << m_name  + ":"<< endl;
}

void CMenu::showCommands() {
    for(int i=0; i<m_commands.size(); i++) {
        cout << to_string(i) + "." + m_commands.at(i)->getName()
                + '(' + m_commands.at(i)->getCommandName() + ')' << endl;
    }
}

std::string CMenu::getUserInput() {
    cout << ":";
    string userInput;
    cin >> userInput;
    return userInput;
}

int CMenu::validateUserInput(string command) {
    // Split input by spaces
    vector<string> commands = stringUtils::splitString(command);

    // Check if command is in the list
    int commandIndex = COMMAND_NOT_IN_LIST;
    for(int i=0; i<m_commands.size(); i++) {
        if (m_commands.at(i)->getCommandName() == commands.at(0))
            commandIndex = i;
    }
    return commandIndex;
}

void CMenu::matchCommand(int commandIndex) {
    if (commandIndex != COMMAND_NOT_IN_LIST)
        m_commands.at(commandIndex)->run();
    else {
        cout << INVALID_COMMAND << endl;
    }
}

std::string CMenu::getName() {
    return m_name;
}

std::string CMenu::getCommandName() {
    return m_commandName;
}

void CMenu::addMenuItem(CMenuItem *command){
    m_commands.push_back(command);
}

bool CMenu::checkQuitLoop(string userInput) {
    return (userInput == "back") ? true: false;
}