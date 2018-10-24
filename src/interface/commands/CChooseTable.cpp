#include <commands/CSetTableElement.h>
#include <commands/CCloneTable.h>
#include <commands/CChangeTableLength.h>
#include "commands/CChooseTable.h"

using namespace std;

const string INVALID_INDEX = "Niepoprawny indeks!";

CChooseTable::CChooseTable(CTableManager *manager) : CCTableCommand(manager) {
    m_arguments_info = "<number>";
    m_arguments_number = 1;
}

bool CChooseTable::validateIndex(std::string userInput) {
    bool isValid = false;
    if (stringUtils::isInt(userInput)) {
        int index = stoi(userInput);
        if (index >= 0 && index < getTableManager()->getSize())
            isValid = true;
    }
    return isValid;
}

void CChooseTable::initTableMenu() {
    CMenu tableMenu("Table menu", "tab");

    CCommand *setElement = new  CSetTableElement(getTableManager());
    CCommand *cloneTable = new CCloneTable(getTableManager());
    CCommand *changeLength = new CChangeTableLength(getTableManager());

    CMenuCommand *setElementMenu = new CMenuCommand(setElement, "set", "Ustaw element");
    CMenuCommand *cloneTableMenu = new CMenuCommand(cloneTable, "clone", "Sklonuj tablicę");
    CMenuCommand *changeLengthMenu = new CMenuCommand(changeLength, "change", "Zmień długość tablicy");

    tableMenu.addMenuItem(setElementMenu);
    tableMenu.addMenuItem(cloneTableMenu);
    tableMenu.addMenuItem(changeLengthMenu);
    tableMenu.run({});
}

void CChooseTable::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string userInput = arguments.at(0);


    if (validateIndex(userInput)) {
        int index = stoi(userInput);
        getTableManager()->setCurrentTable(index);
        initTableMenu();
    } else {
        cout << INVALID_INDEX << endl;
    }
}

