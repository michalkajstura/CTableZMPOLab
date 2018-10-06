//
// Created by michal on 06.10.18.
//

#ifndef CTABLE_CMENU_H
#define CTABLE_CMENU_H

#include <iostream>
#include <vector>

class CMenu {
    protected:
        std::vector<std::string> m_menuItems;

    public:
        ~CMenu();
        void showMenu();
        int numbeOfMenuItems();
};


#endif CTABLE_CMENU_H
