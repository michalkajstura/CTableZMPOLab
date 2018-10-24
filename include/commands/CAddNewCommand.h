#ifndef CTABLE_CADDNEWCOMMAND_H
#define CTABLE_CADDNEWCOMMAND_H

#include "CProgramStructureCommand.h"

class CAddNewCommand : public CProgramStructureCommand {
    public:
        CAddNewCommand(CMenu *menu);
        void runCommand(std::vector<std::string> arguments);
};


#endif //CTABLE_CADDNEWCOMMAND_H
