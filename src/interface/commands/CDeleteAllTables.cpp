#include "../../../include/CDeleteAllTables.h"

void CDeleteAllTables::runCommand() {
    getTableManager()->clear();
}
