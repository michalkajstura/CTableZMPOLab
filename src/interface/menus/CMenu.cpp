//
// Created by michal on 06.10.18.
//

#include "../../../include/CMenu.h"
#include "../../../include/CInterface.h"

using namespace std;

CMenu::~CMenu() {
    m_menuItems.clear();
}

void CMenu::showMenu() {
    for (int i = 0; i < m_menuItems.size(); i++) {
        cout << to_string(i + 1) + "." + m_menuItems.at(i) << endl;
    }
}

int CMenu::numbeOfMenuItems() {
    return m_menuItems.size();
}


