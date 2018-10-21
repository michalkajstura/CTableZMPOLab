#ifndef CTABLE_CDELETEALLTABLES_H
#define CTABLE_CDELETEALLTABLES_H

#include "CCTableCommand.h"
#include <string>
#include <vector>

class CDeleteAllTables: CCTableCommand {
    public:
        CDeleteAllTables(CTableManager *manager);
        void runCommand(std::vector<std::string> arguments) override;
};


#endif //CTABLE_CDELETEALLTABLES_H
