#include "../../../include/CMenu.h"
#include "utils.h"

using namespace std;

const int COMMAND_NOT_IN_LIST = -1;
const string INVALID_COMMAND = "Niepoprawna komenda.";
const string DEFAULT_NAME = "Menu domyślne";
const string TO_MANY_ARGUMENTS_ERROR = "Za dużo argumentów.";


CMenu::CMenu(std::string commandName, std::string name=DEFAULT_NAME) {
    m_name = name;
    m_commandName = commandName;
    m_nextIter = true;          // Menu is running by default
    m_arguments_number = 0;     // Menu has no arguments
}

CMenu::~CMenu() {
    for (vector<CMenuItem*>::iterator iter = m_commands.begin(); iter != m_commands.end(); iter++) {
        CMenuItem *temp = *iter;
        delete temp;
    }
}

void CMenu::run(vector<string> arguments) {
    // Check if there is no additional arguments
    if (arguments.size() != m_arguments_number) {
        cout << TO_MANY_ARGUMENTS_ERROR << endl;
        return;
    }
    while(m_nextIter) {
        showName();
        showCommands();
        string userInput = getUserInput();
        if (checkQuitLoop(userInput)) {
            m_nextIter = false;
        } else {
            parseUserInput(userInput);
        }
    }
}

void CMenu::showName() {
    cout << m_name  + ":"<< endl;
}

void CMenu::showCommands() {
    for(int i=0; i<m_commands.size(); i++) {
        cout << to_string(i) + "." + m_commands.at(i)->getName()
                + m_commands.at(i)->toString() << endl;
    }
}

std::string CMenu::getUserInput() {
    cout << ":";
    string userInput;
    getline(cin, userInput);
    return userInput;
}

void CMenu::parseUserInput(std::string userInput) {
    // Split input by spaces
    vector<string> inputSplitted = stringUtils::splitString(userInput);
    string command = inputSplitted.at(0);
    int commandIndex = validateUserInput(command);
    // Get tail of the vector
    vector<string> arguments(inputSplitted.begin()+1, inputSplitted.end());
    matchCommand(commandIndex, arguments);
}

int CMenu::validateUserInput(string command) {
    // Check if the command is in the list
    int commandIndex = COMMAND_NOT_IN_LIST;
    for(int i=0; i<m_commands.size(); i++) {
        if (m_commands.at(i)->getCommandName() == command)
            commandIndex = i;
    }
    return commandIndex;
}

void CMenu::matchCommand(int commandIndex, vector<string> arguments) {
    if (commandIndex != COMMAND_NOT_IN_LIST)
        m_commands.at(commandIndex)->run(arguments);
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
    return userInput == "back";
}

std::string CMenu::toString() {
    return " (" + m_name +  m_commandName + ")";
}