#include "../../../include/CDeleteAllTables.h"

using namespace std;

CDeleteAllTables::CDeleteAllTables(CTableManager *manager) : CCTableCommand(manager) {
    m_arguments_info = "";
    m_arguments_number = 0;
}

void CDeleteAllTables::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    getTableManager()->clear();
}
