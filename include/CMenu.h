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
        void parseUserInput(std::string userInput);
        int validateUserInput(std::string command);
        void matchCommand(int commandIndex, std::vector<std::string> arguments);
        void printNewLines(int numberOfLines);
        std::vector<CMenuItem*> m_commands;
        bool m_nextIter;
        std::vector<std::string> loadHeaders(std::string stringMenu, int *index);
        bool loadMenu(std::string stringMenu, int *index);

    public:
        CMenu();
        CMenu(std::string commandName, std::string name);
        ~CMenu();
        std::string getName();
        std::string getCommandName();
        std::string toString();
        void run(std::vector<std::string> arguments);
        void addMenuItem(CMenuItem *command);
        bool checkQuitLoop(std::string userInput);
        std::string save();
        bool load(std::string stringMenu);
};

#endif // CTABLE_CMENU_H
