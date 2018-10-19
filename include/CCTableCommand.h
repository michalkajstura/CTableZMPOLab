#ifndef CTABLE_CCTABLECOMMAND_H
#define CTABLE_CCTABLECOMMAND_H

#include "CCommand.h"

class CCTableCommand: public CCommand{
    protected:
        CTableManager *m_tableManager;
    public:
        CCTableCommand(CTableManager *tableManager);
        void runCommand(){};
        CTableManager *getTableManager();
};


#endif //CTABLE_CCTABLECOMMAND_H
