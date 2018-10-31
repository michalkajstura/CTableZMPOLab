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
        std::vector<std::string> loadHeaders(std::string stringMenu, int *index);
        bool loadMenu(std::string stringMenu, int *index);
        std::string findPath(std::string commandName, CMenu* menu, std::string acc);//, std:vector<std::string> *paths);
        bool matchMetaCommand(std::string userInput);
        CMenu *m_root;
        bool m_nextIter;
        std::vector<CMenuItem*> m_commands;

    public:
        CMenu();
        CMenu(std::string commandName, std::string name);
        ~CMenu();
        std::string getName();
        std::string getCommandName();
        std::string toString();
        void run(std::vector<std::string> arguments);
        void addMenuItem(CMenuItem *command);
        std::string save();
        bool load(std::string stringMenu);
        CMenu *getRoot();
        void setRoot(CMenu *root);
        std::string findPath(std::string commandName);
};

#endif // CTABLE_CMENU_H
