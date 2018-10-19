#include "../../include/CTableManager.h"

using namespace std;

CTable* CTableManager::getTable(int index) {
    return m_tables.at(index);
}

void CTableManager::addTable(CTable *newTable) {
    m_tables.push_back(newTable);
}

int CTableManager::getSize() {
    return m_tables.size();
}

void CTableManager::clear() {
    m_tables.clear();
}
