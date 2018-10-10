#ifndef CTABLE_CMENU_H
#define CTABLE_CMENU_H

#include <iostream>
#include <vector>
#include "CTable.h"

class CMenu {
    protected:
        std::vector<std::string> m_menuItems;

    public:
        ~CMenu();
        void showMenu();
        int numberOfMenuItems();
};

#endif CTABLE_CMENU_H
