#include <CTwoNumbersManager.h>
#include "commands/CTwoNumbersCommand.h"

CTwoNumbersCommand::CTwoNumbersCommand(CTwoNumbersManager &manager) {
    m_manager = &manager;
}
