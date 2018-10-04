#include "../include/CTable.h"
#include <iostream>

CTable::CTable() {
    m_name = DEFAULT_NAME;
    m_size = DEFAULT_SIZE;
    m_array = new int[m_size];
    std::cout << "bezp: '" + m_name + "'";
}

CTable::CTable(std::string name, int tableLen) {
    m_name = name;
    m_size = tableLen;
    m_array = new int[m_size];
    std::cout << "parameter: '" + m_name + "'";
}

CTable::CTable(CTable &otherTable, bool *success) {
    copyOfTable(otherTable, success);
}

CTable::~CTable(){
    delete [] m_array;
}

int CTable::getSize() {
    return m_size;
}


void CTable::copyOfTable(CTable otherTable, bool *success) {
    int newSize = otherTable.getSize();
    m_size = newSize;

    // Create new array with length equal to otherTable's array
    int *newArray = new int[newSize];

    // Free memory and assign new array
    delete [] m_array;
    m_array = newArray;

    // Copy elements
    for (int i = 0; i < newSize; i++) {
        newArray[i] = otherTable.getElement(i, success);
        if (!success) return; // ????
    }
}

