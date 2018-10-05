
#include "../../../include/CPrimaryMenu.h"
#include "../../../include/CTable.h"
#include <iostream>
#include "utils.h"

using namespace std;

CPrimaryMenu::CPrimaryMenu() {
    m_menuItems.push_back("Uwtórz tablicę");
    m_menuItems.push_back("Wyświetl wszystkie tablice");
    m_menuItems.push_back("Przejdź do tablicy");
    m_menuItems.push_back("Skasuj wszystkie tablice");
    m_menuItems.push_back("Wyjdź");
}

CPrimaryMenu::~CPrimaryMenu(){
    m_menuItems.clear();
}

void CPrimaryMenu::showMenu() {
    for (int i = 0; i < m_menuItems.size(); i++) {
        cout << to_string(i + 1) + "." + m_menuItems.at(i) << endl;
    }
}

void CPrimaryMenu::createTable() {
    string tableName;

    // Get table name and validate
    cout << "Nazwa: ";
    cin >> tableName;
    cout << "\n";

    if (tableName.empty()) {
        cout << "Wpisano niepoprawną nazwę tablicy. Ustawiam nazwę domyślną" << endl;
        tableName = DEFAULT_NAME;
    }

    // Get size and validate
    string tableSizeString;
    int tableSize;
    cout << "Rozmiar: ";
    cin >> tableSizeString;
    cout << "\n";

    if (stringUtils::isInt(tableSizeString)) {
        tableSize = stoi(tableSizeString);
    } else {
        cout << "Wpisano niepoprawny rozmiar tablicy. Ustawiam rozmiar domyślny" << endl;
        tableSize = DEFAULT_SIZE;
    }

    // Create new table and add it to list
    CTable table = CTable(tableName, tableSize);
    m_tables.push_back(table);
}

void CPrimaryMenu::displayAllTables() {
    for (CTable &table: m_tables) {
        cout << table.toString() << endl;
    }
}

void CPrimaryMenu::deleteAllTables() {
    m_tables.clear();
}

void CPrimaryMenu::goToTable() {

    // Display tables and let user choose
    displayAllTables();
    int userInputString;
    cin >> userInputString;

    // Validate the string
    if ()
}