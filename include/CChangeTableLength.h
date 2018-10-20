#ifndef CTABLE_CCHANGETABLELENGTH_H
#define CTABLE_CCHANGETABLELENGTH_H

#include "CCTableCommand.h"
#include "utils.h"

class CChangeTableLength : public CCTableCommand {
    public:
        CChangeTableLength(CTableManager *manager) : CCTableCommand(manager){}
        void runCommand();
};


#endif //CTABLE_CCHANGETABLELENGTH_H
