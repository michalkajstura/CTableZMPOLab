//
// Created by michal on 05.10.18.
//

#ifndef CTABLE_MENU_H
#define CTABLE_MENU_H

#include "CTable.h"
#include <iostream>
#include <vector>

class CPrimaryMenu {
    private:
        std::vector<std::string> m_menuItems;
        std::vector<CTable> m_tables;

    public:
        CPrimaryMenu();
        void showMenu();
        void createTable();
        void displayAllTables();
        void goToTable();
        void deleteAllTables();
};


#endif //CTABLE_MENU_H
