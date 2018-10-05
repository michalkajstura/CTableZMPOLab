#ifndef CTABLE_CINTERFACE_H
#define CTABLE_CINTERFACE_H

#include <iostream>
#include <vector>
#include "CTable.h"
#include "../include/utils.h"

class CInterface {

    private:
        void printTables();
        void showMenu();
        std::string getUserInput();
        bool validateInput(std::string userInput, int numberOfMenuItems);
        void processInput(std::string userInput);

        void createTable();
        void displayAllTables();
        void goToTable();
        void deleteAllTables();



        std::vector<std::string> m_menuItems;
        std::vector<std::string> m_tableMenuItems;
        std::vector<CTable> m_tables;

    public:
        CInterface();
        ~CInterface();
        void run();
};


#endif //CTABLE_CINTERFACE_H
