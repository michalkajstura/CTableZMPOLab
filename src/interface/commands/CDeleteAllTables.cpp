#include "commands/CDeleteAllTables.h"

using namespace std;

CDeleteAllTables::CDeleteAllTables(CTableManager *manager) : CCTableCommand(manager) {
    m_arguments_info = "";
    m_arguments_number = 0;
    m_help_info = "Usuwa wszystkie tablice";
}

void CDeleteAllTables::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    getTableManager()->clear();
}
