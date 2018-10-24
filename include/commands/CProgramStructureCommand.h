#ifndef CTABLE_CPROGRAMSTRUCTURECOMMAND_H
#define CTABLE_CPROGRAMSTRUCTURECOMMAND_H

#include <CMenu.h>
#include "CCommand.h"

class CProgramStructureCommand : public CCommand {
    protected:
        bool validateCommandName(std::string commandName);
        CMenu *m_menu;
    public:
        CProgramStructureCommand(CMenu *menu);
        virtual void runCommand(std::vector<std::string> arguments)=0;
};

#endif //CTABLE_CPROGRAMSTRUCTURECOMMAND_H
