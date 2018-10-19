#include "../../../include/CShowAllTables.h"

using namespace std;

void CShowAllTables::runCommand() {
    for(int i=0; i<m_tableManager->getSize(); i++) {
        cout <<  m_tableManager->getTable(i)->toString() << endl;
    }
}
