#include "commands/CCloneTable.h"

using namespace std;

CCloneTable::CCloneTable(CTableManager *manager) : CCTableCommand (manager) {
    m_arguments_info = "";
    m_arguments_number = 0;
}

void CCloneTable::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;

    CTableManager *manager = getTableManager();
    CTable *newTable = new CTable(*(manager->getCurrentTable()));
    manager->addTable(newTable);
}