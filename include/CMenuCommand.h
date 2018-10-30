#ifndef CTABLE_CMENUCOMMAND_H
#define CTABLE_CMENUCOMMAND_H

#include "CMenuItem.h"
#include "commands/CCommand.h"

class CMenuCommand: public CMenuItem {
    private:
        CCommand *m_command;
    public:
        CMenuCommand();
        CMenuCommand(CCommand *command, std::string commandName, std::string name);
        ~CMenuCommand();
        std::string getName() override;
        std::string getCommandName() override;
        std::string toString() override;
        void run(std::vector<std::string> arguments);
        std::string save();
        bool load(std::string stringCommand, int *index);
        CCommand *getCommand();


};

#endif //CTABLE_CMENUCOMMAND_H
