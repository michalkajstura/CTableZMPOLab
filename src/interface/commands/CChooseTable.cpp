#include <CSetTableElement.h>
#include <CCloneTable.h>
#include <CChangeTableLength.h>
#include "CChooseTable.h"

using namespace std;

const string CHOOSE_TABLE_NUMBER = "Wybierz numer: ";
const string INVALID_INDEX = "Niepoprawny indeks!";

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

    CSetTableElement setElement(getTableManager());
    CCloneTable cloneTable(getTableManager());
    CChangeTableLength changeLength(getTableManager());

    CMenuCommand setElementMenu(setElement, "set", "Ustaw element");
    CMenuCommand cloneTableMenu(cloneTable, "clone", "Sklonuj tablicę");
    CMenuCommand changeLengthMenu(changeLength, "change", "Zmień długość tablicy");

    tableMenu.addMenuItem(&setElementMenu);
    tableMenu.addMenuItem(&cloneTableMenu);
    tableMenu.addMenuItem(&changeLengthMenu);
    tableMenu.run();
}

void CChooseTable::runCommand() {
    cout << CHOOSE_TABLE_NUMBER;
    string userInput;
    cin >> userInput;

    if (validateIndex(userInput)) {
        int index = stoi(userInput);
        getTableManager()->setCurrentTable(index);
        initTableMenu();
    } else {
        cout << INVALID_INDEX << endl;
    }
}

