#ifndef CTABLE_CCOMMANDOPENMENU_H
#define CTABLE_CCOMMANDOPENMENU_H

#include "utils.h"
#include "CCTableCommand.h"

class CCreateTable: public CCTableCommand {
    public:
        CCreateTable(CTableManager *manager) : CCTableCommand(manager) {}
        void runCommand() override;
};


#endif //CTABLE_CCOMMANDOPENMENU_H
