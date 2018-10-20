#include "CCloneTable.h"

using namespace std;

void CCloneTable::runCommand() {
    CTableManager *manager = getTableManager();
    CTable *newTable = new CTable(*(manager->getCurrentTable()));
    manager->addTable(newTable);
}