#include "../../include/CTableManager.h"

using namespace std;

CTableManager::~CTableManager() {
    clear();
}

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
    for (vector<CTable*>::iterator iter = m_tables.begin(); iter != m_tables.end(); iter++) {
        CTable *temp = *iter;
        delete temp;
    }
}

CTable* CTableManager::getCurrentTable() {
    return m_currentTable;
}

void CTableManager::setCurrentTable(int index) {
    m_currentTable = m_tables.at(index);
}

void CTableManager::deleteTable(int index){
    m_tables.erase(m_tables.begin() + index);
}
