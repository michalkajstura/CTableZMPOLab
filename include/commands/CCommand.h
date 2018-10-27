#ifndef CTABLE_CCOMMAND_H
#define CTABLE_CCOMMAND_H

#include "CTableManager.h"

const std::string INVALID_NUMBER_OF_ARGUMENTS = "Niepoprawna ilość argumentów.";

class CCommand {
    protected:
        std::string m_arguments_info;
        std::string m_help_info;
        int m_arguments_number;
        bool validaterNumberOfArguments(int numberOfArguments);
    public:
        CCommand();
        virtual void runCommand(std::vector<std::string> arguments);
        std::string getArgumentsInfo();
        std::string getHelp();
};


#endif //CTABLE_CCOMMAND_H
