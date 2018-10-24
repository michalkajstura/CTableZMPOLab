#include "commands/CShowAllTables.h"

using namespace std;

CShowAllTables::CShowAllTables(CTableManager *manager) : CCTableCommand(manager) {
    m_arguments_info = "";
    m_arguments_number = 0;
}

void CShowAllTables::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;

    for(int i=0; i<m_tableManager->getSize(); i++) {
        cout << to_string(i) + ". " + m_tableManager->getTable(i)->toString() << endl;
    }
}
