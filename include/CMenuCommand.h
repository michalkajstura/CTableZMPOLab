#ifndef CTABLE_CMENUCOMMAND_H
#define CTABLE_CMENUCOMMAND_H

#include "CMenuItem.h"
#include "commands/CCommand.h"

class CMenuCommand: public CMenuItem {
    private:
        CCommand *m_command;
    public:
        CMenuCommand(CCommand *command, std::string commandName, std::string name);
        ~CMenuCommand();
        std::string getName() override;
        std::string getCommandName() override;
        std::string toString() override;
        void run(std::vector<std::string> arguments);
};

#endif //CTABLE_CMENUCOMMAND_H
