#include "../../../include/CDeleteAllTables.h"

void CDeleteAllTables::runCommand() {
    m_tableManager->clear();
}
