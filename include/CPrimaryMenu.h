#ifndef CTABLE_MENU_H
#define CTABLE_MENU_H

#include "CMenu.h"


class CPrimaryMenu: public CMenu {
    private:
    void createTable();
    void displayAllTables();
    void goToTable(int tableNumber);
    void deleteAllTables();

    public:
        CPrimaryMenu();
};

#endif //CTABLE_MENU_H
