#ifndef CTABLE_CCLONETABLE_H
#define CTABLE_CCLONETABLE_H

#include "CCTableCommand.h"

class CCloneTable : public CCTableCommand {
    public:
        CCloneTable(CTableManager *manager) : CCTableCommand(manager) {}
        void runCommand();
};


#endif //CTABLE_CCLONETABLE_H
