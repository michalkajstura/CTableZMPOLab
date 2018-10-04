#include "../include/CTable.h"
#include <iostream>
#include <cstring>

CTable::CTable() {
    m_name = DEFAULT_NAME;
    m_size = DEFAULT_SIZE;
    m_array = new int[m_size];
    fillArrayWithDefaultValue();
    std::cout << "bezp: '" + m_name + "'";
}

CTable::CTable(std::string name, int tableLen) {
    m_name = name;
    m_size = tableLen;
    m_array = new int[m_size];
    fillArrayWithDefaultValue();
    std::cout << "parameter: '" + m_name + "'";
}

//CTable::CTable(CTable &otherTable, bool *success) {
//    copyOfTable(otherTable, success);
//}

CTable::~CTable(){
    delete [] m_array;
}

void CTable::fillArrayWithDefaultValue() {
    for (int i = 0; i < m_size; i++) {
        m_array[i] = DEFAULT_VALUE;
    }
}

int CTable::getSize() {
    return m_size;
}

//void CTable::copyOfTable(CTable otherTable, bool *success) {
//    int newSize = otherTable.getSize();
//    m_size = newSize;
//
//    // Create new array with length equal to otherTable's array
//    int *newArray = new int[newSize];
//
//    // Free memory and assign new array
//    delete [] m_array;
//    m_array = newArray;
//
//    // Copy elements
//    for (int i = 0; i < newSize; i++) {
//        newArray[i] = otherTable.getElement(i, success);
//        if (!success) return; // ????
//    }
//}

bool CTable::setElement(int index, int element) {
    if (index < 0 || index >= m_size)
        return false;
    m_array[index] = element;
    return true;
}

void CTable::changeTableLength(int newLength) {
    int *newArray = new int[newLength];

    if (newLength < m_size) {
        // Copy elements from 0 to newLength, other elements are lost
        std::memcpy(newArray, m_array, sizeof(int) * newLength);
    } else {
        // if new array is longer, copy all elements from old array and fill the rest
        std::memcpy(newArray, m_array, sizeof(int) * m_size);
        std::memset(newArray + m_size, DEFAULT_VALUE, sizeof(int) * (newLength - m_size)); //TODO: czytelność
    }

    // Free memory and set new array
    delete [] m_array;
    m_size = newLength;
    m_array = newArray;
}

std::string CTable::toString() {
    std::string stringRepresentation = "";
    for (int i = 0; i < m_size - 1; i++) {
        std::string stringOfNumber = std::to_string(m_array[i]) + ", ";
        stringRepresentation.append(stringOfNumber);
    }
    // Append last element without comma and space
    stringRepresentation.append(std::to_string(m_array[m_size - 1]));
    return stringRepresentation;
}


