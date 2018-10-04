#include "../include/CTable.h"

CTable::CTable() {
    m_name = DEFAULT_NAME;
    m_size = DEFAULT_SIZE;
    m_array = new int[m_size];
}

CTable::CTable(std::string name, int tableLen) {
    m_name = name;
    m_size = tableLen;
    m_array = new int[m_size];
}

CTable::~CTable() {
    delete [] m_array;
}

