#ifndef CTABLE_CMENUCOMMAND_H
#define CTABLE_CMENUCOMMAND_H

#include "CMenuItem.h"
#include "CCommand.h"

class CMenuCommand: public CMenuItem {
    private:
        CCommand *m_command;

    public:
        CMenuCommand(CCommand &command, std::string commandName, std::string name);
        std::string getName() override;
        std::string getCommandName() override;
        void run() override;
        void assignCommand(CCommand *m_command);
};


#endif //CTABLE_CMENUCOMMAND_H
