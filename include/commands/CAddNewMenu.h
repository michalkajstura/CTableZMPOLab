#ifndef CTABLE_CADDNEWMENU_H
#define CTABLE_CADDNEWMENU_H

#include "CProgramStructureCommand.h"

class CAddNewMenu : public CProgramStructureCommand {
    private:
        bool validateCommandName(std::string commandName);
    public:
        CAddNewMenu(CMenu *menu);
        void runCommand(std::vector<std::string> arguments);
};


#endif //CTABLE_CADDNEWMENU_H
