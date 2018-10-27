#ifndef CTABLE_CHELP_H
#define CTABLE_CHELP_H

#include <CMenuItem.h>
#include <CMenuCommand.h>
#include "CCommand.h"

class CHelp : public CCommand {
    private:
        CMenuCommand *findCommand(std::string commandName);
        std::vector<CMenuCommand*> *m_commands;
    public:
        CHelp(std::vector<CMenuCommand*> &commands);
        virtual void runCommand(std::vector<std::string> arguments);
};


#endif //CTABLE_CHELP_H
