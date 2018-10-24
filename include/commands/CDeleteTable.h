#ifndef CTABLE_CDELETETABLE_H
#define CTABLE_CDELETETABLE_H

#include "CCTableCommand.h"
#include <string>

class CDeleteTable : public CCTableCommand {
    public:
        CDeleteTable(CTableManager *manager);
        void runCommand(std::vector<std::string> arguments);
};


#endif //CTABLE_CDELETETABLE_H
