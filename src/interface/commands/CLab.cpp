#include <CMenu.h>
#include "commands/CLab.h"

using namespace std;

const string BAD_ARGUMENT = "Zły argument!";

CAddCommand::CAddCommand(CTwoNumbersManager &manager) : CTwoNumbersCommand(manager) {
    m_arguments_info = "";
    m_arguments_number = 0;
}

void CAddCommand::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    m_manager->add();
}

CSubtractCommand::CSubtractCommand(CTwoNumbersManager &manager) : CTwoNumbersCommand(manager) {
    m_arguments_info = "";
    m_arguments_number = 0;
}

void CSubtractCommand::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    m_manager->subtract();
}

CResetCommand::CResetCommand(CTwoNumbersManager &manager) : CTwoNumbersCommand(manager) {
    m_arguments_info = "";
    m_arguments_number = 0;
}

void CResetCommand::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    m_manager->reset();
}

CGotoOperations::CGotoOperations(CTwoNumbersManager &manager) : CTwoNumbersCommand(manager){
    m_arguments_info = "";
    m_arguments_number = 0;
}

void CGotoOperations::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    CCommand *add = new CAddCommand(*m_manager);
    CCommand *subtract = new CSubtractCommand(*m_manager);
    CCommand *defaultCommand = new CCommand();
    CMenu menu("operations", "Operations");
    menu.addMenuItem(new CMenuCommand(add, "add", "Dodawanie"));
    menu.addMenuItem(new CMenuCommand(subtract, "sub", "Odejmowanie"));
    menu.addMenuItem(new CMenuCommand(defaultCommand, "default", "Domyślna"));
    menu.run(std::vector<std::string>());
}

CSetA::CSetA(CTwoNumbersManager &manager) : CTwoNumbersCommand(manager) {
    m_arguments_info = "<numer>";
    m_arguments_number = 1;
}

void CSetA::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string number = arguments.at(0);
    if (stringUtils::isInt(number))
        m_manager->setLiczba1(stoi(number));
    else
        cout << BAD_ARGUMENT << endl;
}

CSetB::CSetB(CTwoNumbersManager &manager) : CTwoNumbersCommand(manager) {
    m_arguments_info = "<numer>";
    m_arguments_number = 1;
}

void CSetB::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string number = arguments.at(0);
    if (stringUtils::isInt(number))
        m_manager->setLiczba2(stoi(number));
    else
        cout << BAD_ARGUMENT << endl;
}


