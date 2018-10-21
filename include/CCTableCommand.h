#ifndef CTABLE_CCTABLECOMMAND_H
#define CTABLE_CCTABLECOMMAND_H

#include "CCommand.h"

class CCTableCommand: public CCommand{
    protected:
        CTableManager *m_tableManager;
    public:
        CCTableCommand(CTableManager *tableManager);
        virtual void runCommand(std::vector<std::string> arguments)=0;
        CTableManager *getTableManager();
};


#endif //CTABLE_CCTABLECOMMAND_H
