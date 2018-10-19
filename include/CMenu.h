#ifndef CTABLE_CMENU_H
#define CTABLE_CMENU_H

#include <iostream>
#include <vector>
#include "CMenuItem.h"
#include "CMenuCommand.h"

class CMenu: public CMenuItem {
    private:
        void showName();
        void showCommands();
        std::string getUserInput();
        int validateUserInput(std::string command);
        void matchCommand(int commandIndex);
        std::vector<CMenuItem*> m_commands;
        bool m_nextIter;

    public:
        CMenu(std::string commandName, std::string name);
        ~CMenu();
        std::string getName() override;
        std::string getCommandName() override;
        void run() override;
        void addMenuItem(CMenuItem *command);
        bool checkQuitLoop(std::string userInput);
};

#endif CTABLE_CMENU_H
