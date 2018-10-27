#ifndef CTABLE_CADDCOMMAND_H
#define CTABLE_CADDCOMMAND_H


#include "CTwoNumbersCommand.h"

class CAddCommand : public CTwoNumbersCommand {
    public:
        CAddCommand(CTwoNumbersManager  &manager);
        void runCommand(std::vector<std::string> arguments);
};

class CSubtractCommand : public CTwoNumbersCommand {
    public:
        CSubtractCommand(CTwoNumbersManager  &manager);
        void runCommand(std::vector<std::string> arguments);
};

class CResetCommand : public CTwoNumbersCommand {
    public:
        CResetCommand(CTwoNumbersManager  &manager);
        void runCommand(std::vector<std::string> arguments);
};

class CGotoOperations: public CTwoNumbersCommand {
    public:
        CGotoOperations(CTwoNumbersManager &manager);
        void runCommand(std::vector<std::string> arguments);
};

class CSetA: public CTwoNumbersCommand {
    public:
        CSetA(CTwoNumbersManager &manager);
        void runCommand(std::vector<std::string> arguments);
};

class CSetB: public CTwoNumbersCommand {
public:
    CSetB(CTwoNumbersManager &manager);
    void runCommand(std::vector<std::string> arguments);
};

#endif //CTABLE_CADDCOMMAND_H
