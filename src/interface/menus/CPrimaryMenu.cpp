
#include "../../../include/CPrimaryMenu.h"
#include "../../../include/CTableMenu.h"
#include "../../../include/CTable.h"
#include "../../../include/utils.h"
#include <iostream>

using namespace std;

CPrimaryMenu::CPrimaryMenu() {
    m_menuItems.push_back("Uwtórz tablicę");
    m_menuItems.push_back("Wyświetl wszystkie tablice");
    m_menuItems.push_back("Przejdź do tablicy");
    m_menuItems.push_back("Skasuj wszystkie tablice");
    m_menuItems.push_back("Wyjdź");
}

