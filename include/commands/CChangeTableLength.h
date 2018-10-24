#ifndef CTABLE_CCHANGETABLELENGTH_H
#define CTABLE_CCHANGETABLELENGTH_H

#include "CCTableCommand.h"
#include "utils.h"

class CChangeTableLength : public CCTableCommand {
    public:
        CChangeTableLength(CTableManager *manager);
        void runCommand(std::vector<std::string> arguments);
};


#endif //CTABLE_CCHANGETABLELENGTH_H
