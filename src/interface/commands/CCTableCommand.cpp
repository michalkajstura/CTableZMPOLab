#include "commands/CCTableCommand.h"


CCTableCommand::CCTableCommand(CTableManager *tableManager) {
    m_tableManager = tableManager;
}

CTableManager* CCTableCommand::getTableManager() {
    return m_tableManager;
}

