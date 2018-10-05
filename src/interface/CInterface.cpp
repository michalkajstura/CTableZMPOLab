//
// Created by michal on 05.10.18.
//

#include "../../include/CInterface.h"

using namespace std;

CInterface::CInterface() {
    // Primary menu items
    m_menuItems.push_back("Uwtórz tablicę");
    m_menuItems.push_back("Wyświetl wszystkie tablice");
    m_menuItems.push_back("Przejdź do tablicy");
    m_menuItems.push_back("Skasuj wszystkie tablice");
    m_menuItems.push_back("Wyjdź");

    // Table menu items
    m_tableMenuItems.push_back("Określ długość tablicy");
    m_tableMenuItems.push_back("Zmień nazwę tablicy");
    m_tableMenuItems.push_back("Sklonuj tablicę");
    m_tableMenuItems.push_back("Wyświetl tablicę");
    m_tableMenuItems.push_back("Ustaw komórkę tablicy");
    m_tableMenuItems.push_back("Skasuj tablicę");
}

CInterface::~CInterface(){
    m_menuItems.clear();
    m_tableMenuItems.clear();
    m_tables.clear();
}

void CInterface::showMenu() {
    for (int i = 0; i < m_menuItems.size(); i++) {
        cout << to_string(i + 1) + "." + m_menuItems.at(i) << endl;
    }
}

string CInterface::getUserInput() {
    string userInput;
    cin >> userInput;
    return userInput;
}

bool CInterface::validateInput(string userInput, int numberOfMenuItems) {
     bool isInt = stringUtils::isInt(userInput);
     if (isInt) {
         int inputInt = stoi(userInput);
         bool isInRange = inputInt > 0 && inputInt <= numberOfMenuItems;
         return isInRange;
     }
    return false;
}

void CInterface::processInput(std::string userInput) {
    int inputInt = stoi(userInput);
    switch (inputInt) {

    }
}



void CInterface::run() {
    bool exit = false;
//    while (!exit) {
        showMenu();
        // Show menu
        // Read input from user
        // Validate input
        // Do stuff
//    }
}
