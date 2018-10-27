#ifndef CTABLE_CTWONUMBERSCOMMAND_H
#define CTABLE_CTWONUMBERSCOMMAND_H


#include "CCommand.h"
#include "CTwoNumbersManager.h"

class CTwoNumbersCommand : public CCommand {
    protected:
        CTwoNumbersManager *m_manager;
    public:
        CTwoNumbersCommand(CTwoNumbersManager &manager);
        virtual void runCommand(std::vector<std::string> arguments)=0;
};


#endif //CTABLE_CTWONUMBERSCOMMAND_H
