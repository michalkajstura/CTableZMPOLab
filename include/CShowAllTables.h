#ifndef CTABLE_CSHOWALLTABLES_H
#define CTABLE_CSHOWALLTABLES_H

#include "CCTableCommand.h"

class CShowAllTables: public CCTableCommand {
    public:
        CShowAllTables(CTableManager *manager);
        void runCommand(std::vector<std::string> arguments) override;
};


#endif //CTABLE_CSHOWALLTABLES_H
