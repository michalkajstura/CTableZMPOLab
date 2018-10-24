#ifndef CTABLE_CCHOOSETABLE_H
#define CTABLE_CCHOOSETABLE_H

#include "CCTableCommand.h"
#include "CMenu.h"
#include "utils.h"

class CChooseTable : public CCTableCommand {
    private:
        bool validateIndex(std::string userInput);
        void initTableMenu();
    public:
        CChooseTable(CTableManager *manager);
        void runCommand(std::vector<std::string>);
};


#endif //CTABLE_CCHOOSETABLE_H
