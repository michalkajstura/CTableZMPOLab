#ifndef CTABLE_CTABLEMANAGER_H
#define CTABLE_CTABLEMANAGER_H

#include "CTable.h"
#include <vector>

class CTableManager {
    private:
        std::vector<CTable*> m_tables;
        CTable* m_currentTable;
    public:
        ~CTableManager();
        void addTable(CTable *newTable);
        CTable *getTable(int index);
        int getSize();
        void clear();
        CTable* getCurrentTable();
        void setCurrentTable(int index);
        void deleteTable(int index);
};

#endif //CTABLE_CTABLEMANAGER_H
