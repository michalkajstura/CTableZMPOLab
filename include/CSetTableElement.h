#ifndef CTABLE_CSETTABLEELEMENT_H
#define CTABLE_CSETTABLEELEMENT_H

#include "CCTableCommand.h"
#include "utils.h"

class CSetTableElement : public CCTableCommand {
    public:
        CSetTableElement(CTableManager *manager) : CCTableCommand(manager){}
        void runCommand();
};


#endif //CTABLE_CSETTABLEELEMENT_H
