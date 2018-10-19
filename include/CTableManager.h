#ifndef CTABLE_CTABLEMANAGER_H
#define CTABLE_CTABLEMANAGER_H

#include "CTable.h"
#include <vector>

class CTableManager {
    private:
        std::vector<CTable*> m_tables;
    public:
        void addTable(CTable *newTable);
        CTable *getTable(int index);
        int getSize();
        void clear();
};

#endif //CTABLE_CTABLEMANAGER_H
