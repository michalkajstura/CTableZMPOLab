#ifndef CTABLE_CCOMMAND_H
#define CTABLE_CCOMMAND_H

#include "CTableManager.h"

const std::string INVALID_NUMBER_OF_ARGUMENTS = "Niepoprawna ilość argumentów.";

class CCommand {
    protected:
        std::string m_arguments_info;
        int m_arguments_number;
        bool validaterNumberOfArguments(int numberOfArguments);
    public:
        virtual void runCommand(std::vector<std::string> arguments);
        std::string getArgumentsInfo();
};


#endif //CTABLE_CCOMMAND_H
