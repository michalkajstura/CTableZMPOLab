#ifndef CTABLE_CINTERFACE_H
#define CTABLE_CINTERFACE_H

#include <vector>
#include <iostream>
#include "utils.h"
#include "CTable.h"
#include "CMenu.h"
#include "CPrimaryMenu.h"
#include "CTableMenu.h"
#define PRIMARY_MENU 0
#define TABLE_MENU 1

class CInterface {

    private:
        void showMenu();
        std::string getUserInput();
        void clearScreen();
        bool validateInput(std::string userInput, int rangeOfInput);
        void processInput(std::string userInput);
        CMenu *getCurrentMenu();
        void waitForUser();

        // Primary menu
        void processPrimaryMenu(int userInput);
        void createTable();
        void displayAllTables();
        void goToTable();
        void deleteAllTables();
        void quit();

        // Secondary menu
        void processTableMenu(int userInput);
        void printTableLength();
        void changeTableName();
        void changeTableLength();
        void cloneTable();
        void displayTable();
        void setTableElement();
        void deleteTable();
        void backToPrimaryMenu();

        std::vector<CTable*> m_tables;
        CTable *m_currentlyOperatedTable;
        int m_currentMenu;
        CMenu m_menu;
        bool m_exitLoop;

    public:
        CInterface();
        ~CInterface();
        void run();
};

#endif //CTABLE_CINTERFACE_H
