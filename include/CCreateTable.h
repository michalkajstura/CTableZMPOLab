#ifndef CTABLE_CCOMMANDOPENMENU_H
#define CTABLE_CCOMMANDOPENMENU_H

#include "utils.h"
#include "CCTableCommand.h"

class CCreateTable: public CCTableCommand {
    public:
        CCreateTable(CTableManager *manager);
        void runCommand(std::vector<std::string> arguments) override;
};


#endif //CTABLE_CCOMMANDOPENMENU_H
