#ifndef CTABLE_CCLONETABLE_H
#define CTABLE_CCLONETABLE_H

#include "CCTableCommand.h"
#include <vector>
#include <string>

class CCloneTable : public CCTableCommand {
    public:
        CCloneTable(CTableManager *manager);
        void runCommand(std::vector<std::string> arguments);
};


#endif //CTABLE_CCLONETABLE_H
