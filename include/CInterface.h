#ifndef CTABLE_CINTERFACE_H
#define CTABLE_CINTERFACE_H

#include <iostream>
#include "utils.h"

class CInterface {

    private:
        void printTables();
        void showMenu();
        std::string getUserInput();
        bool validateInput(std::string userInput, int numberOfMenuItems);
        void processInput(std::string userInput);

    public:
        CInterface();
        ~CInterface();
        void run();
};


#endif //CTABLE_CINTERFACE_H
