#include <commands/CHelp.h>
#include "../../../include/CMenu.h"
#include "utils.h"

using namespace std;

const int COMMAND_NOT_IN_LIST = -1;
const string INVALID_COMMAND = "Niepoprawna komenda";
const string DEFAULT_NAME = "Menu domyślne";
const string TO_MANY_ARGUMENTS_ERROR = "Za dużo argumentów.";
const string EXPECTED_SEMICOLON= "Miało być: ;";

CMenu::CMenu() {
    m_nextIter = true;
    m_arguments_number = 0;
}

CMenu::CMenu(std::string commandName, std::string name=DEFAULT_NAME) {
    m_name = name;
    m_commandName = commandName;
    m_nextIter = true;          // Menu is running by default
    m_arguments_number = 0;     // Menu has no arguments
    addMenuItem(new CMenuCommand(new CHelp(m_commands), "help", "Pomoc"));
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
    m_nextIter = true;
    while(m_nextIter) {
        showName();
        showCommands();
        string userInput = getUserInput();
        printNewLines(2);
        if (checkQuitLoop(userInput)) {
            m_nextIter = false;
        } else {
            parseUserInput(userInput);
        }
        // Print few newlines to separate from previous iterations
        printNewLines(2);
    }

}

void CMenu::showName() {
    cout << m_name  + " (" + m_commandName + ")" + ":"<< endl;
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
    return " (" + m_commandName + ")";
}

void CMenu::printNewLines(int numberOfLines) {
    for (int i=0; i < numberOfLines; i++) {
        cout << "\n";
    }
}

std::string CMenu::save() {
    string stringMenu = "('" + getName() +"','" + getCommandName() + "';" ;
    for (int i=0; i < m_commands.size(); i++) {
        stringMenu += m_commands.at(i)->save() + ((i == m_commands.size() - 1) ? "" : ",");
    }
    return stringMenu + ")";
}



bool CMenu::load(std::string stringMenu) {
    int index = 0;
    return loadMenu(stringMenu, &index);
}

bool CMenu::loadMenu(std::string stringMenu, int *index) {

    vector<string> headers = loadHeaders(stringMenu, index);
    if (headers.size() == 0) return false;
    m_name = headers.at(0);
    m_commandName = headers.at(1);

    bool stop = false;
    while (*index < stringMenu.length() && !stop) {
        char charAt = stringMenu.at(*index);
        if (charAt == ')')
            stop = true;
        else if (charAt == '[') {
            CMenuCommand *command = new CMenuCommand();
            command->load(stringMenu, index);
            addMenuItem(command);
        } else if (charAt == '(') {
            CMenu *menu = new CMenu();
            menu->loadMenu(stringMenu, index);
            addMenuItem(menu);
        } else if (charAt == ',')
            (*index)++;
        else {
            cerr << EXPECTED_SEMICOLON + INSTEAD + "at " + to_string(*index) << endl;
            return false;
        }
    }
    return true;
}

std::vector<std::string> CMenu::loadHeaders(std::string stringMenu, int *index) {
    vector<string> headers;
    string buffer = "";
    // Don't read first parenthesis
    (*index)++;
    bool stop = false;
    while(*index < stringMenu.length() && !stop) {
        char charAt = stringMenu.at(*index);
        if (charAt == ';') {
            (*index)++;
            stop = true;
        } else if (charAt == '\'') {
            buffer = loadString(stringMenu, index);
            headers.push_back(buffer);
        } else if (charAt == ',')
            (*index)++;
        else {
            cout << EXPECTED_SEMICOLON + INSTEAD + charAt << endl;
            return {};
        }
    }
    if (headers.size() == 2) {
        return headers;
    } else {
        cout << INVALID_NUMBER_OF_ARGUMENTS << endl;
        return {};
    }
}

