#include "../../include/CTable.h"

CTable::CTable() {
    m_name = DEFAULT_NAME;
    m_size = DEFAULT_SIZE;
    m_array = new int[m_size];
    arrayUtils::fillArray(0, m_size, DEFAULT_VALUE, m_array);
    std::cout << "bezp: '" + m_name + "'";
}

CTable::CTable(std::string name, int tableLen) {
    m_name = name;
    m_size = tableLen;
    m_array = new int[m_size];
    arrayUtils::fillArray(0, m_size, DEFAULT_VALUE, m_array);
    std::cout << "parameter: '" + m_name + "'" << std::endl;
}

CTable::CTable(CTable &otherTable, bool *p_success) {
    m_name = otherTable.m_name + "_copy";
    m_size = DEFAULT_SIZE; //
    m_array = new int[m_size];
    copyOfTable(otherTable, p_success);
    std::cout << "kopiuj: '" + otherTable.m_name + "'" << std::endl;
}

CTable::~CTable(){
    std::cout << "usuwam:" + m_name << std::endl;
    delete [] m_array;
}

int CTable::getSize() {
    return m_size;
}

bool CTable::checkIfIndexOutOfBorder(int index) {
    if (index < 0 || index >= m_size) return false;
    else return true;
}

int CTable::getElement(int index, bool *p_success) {
    *p_success = checkIfIndexOutOfBorder(index);
    if (*p_success)
        return m_array[index];
    else
        return DEFAULT_VALUE;
}

void CTable::setElement(int index, int element, bool *p_success) {
    *p_success = checkIfIndexOutOfBorder(index);
    if (*p_success)
        m_array[index] = element;
    }


void CTable::copyOfTable(CTable &otherTable, bool *p_success) {
    int newSize = otherTable.getSize();
    delete [] m_array;
    m_size = newSize;

    // Create new array with length equal to otherTable's array
    int *newArray = new int[newSize];

    // Free memory and assign a new array
    m_array = newArray;

    // Copy elements
    for (int i = 0; i < newSize; i++) {
        newArray[i] = otherTable.getElement(i, p_success);
        if (!p_success) return; // ????
    }
}
CTable CTable::clone(bool *p_success) {
//    CTable newTable = CTable();
//    newTable.copyOfTable(*this, p_success);
//    return newTable;
    return CTable(*this, p_success);
}

void CTable::changeTableLength(int newLength) {
    int *newArray = new int[newLength];

    if (newLength < m_size) {
        // Copy elements from 0 to newLength, other elements are lost
        arrayUtils::copyArray(m_array, newArray, newLength);
    } else {
        // if new array is longer, copy all elements from old array and fill the rest
        arrayUtils::copyArray(m_array, newArray, m_size);
        arrayUtils::fillArray(m_size, newLength, DEFAULT_VALUE, newArray);
    }

    // Free memory and set new array
    delete [] m_array;
    m_size = newLength;
    m_array = newArray;
}

std::string CTable::toString() {
    std::string stringRepresentation;
    for (int i = 0; i < m_size - 1; i++) {
        std::string stringOfNumber = std::to_string(m_array[i]) + ", ";
        stringRepresentation.append(stringOfNumber);
    }
    // Append last element without comma and space
    stringRepresentation.append(std::to_string(m_array[m_size - 1]));
    return stringRepresentation;
}

