#include "../../include/CTable.h"

using namespace std;

const int DEFAULT_SIZE = 10;
const int DEFAULT_VALUE = 0;
const string DEFAULT_NAME = "Tablica";
const string COPY = "_copy";
const string NO_PARAMETERS = "bezb: ";
const string WITH_PARAMETERS = "param: ";
const string COPY_MESSAGE = "kopiuj: ";
const string DELETE_MESSAGE = "usuwam: ";
const string COPY_OF_TABLE_FAILED = "Kopiowanie tablicy się nie powiodło";

CTable::CTable() {
    m_name = DEFAULT_NAME;
    m_size = DEFAULT_SIZE;
    m_array = new int[m_size];
    arrayUtils::fillArray(0, m_size, DEFAULT_VALUE, m_array);
    cout << NO_PARAMETERS + m_name;
}

CTable::CTable(std::string name, int tableLen) {
    m_name = name;
    m_size = tableLen;
    m_array = new int[m_size];
    arrayUtils::fillArray(0, m_size, DEFAULT_VALUE, m_array);
    cout << WITH_PARAMETERS + m_name << endl;
}

CTable::CTable(const CTable &otherTable) {
    m_name = otherTable.getName() + COPY;
    m_array = nullptr;
    copyOfTable(otherTable);
    cout << COPY_MESSAGE + otherTable.m_name << endl;
}

CTable::~CTable(){
    std::cout << DELETE_MESSAGE + m_name << std::endl;
    delete [] m_array;
}

int CTable::getSize() const {
    return m_size;
}

void CTable::doubleArray() {
    int newSize = m_size * 2;
    int *newArray = new int[newSize];

    for (int i=0; i<newSize; i++) {
        newArray[i] = m_array[i%m_size];
    }

    m_size = newSize;
    delete [] m_array;
    m_array = newArray;
}

bool CTable::checkIfIndexOutOfBorder(int index) const {
    if (index < 0 || index >= m_size) return false;
    else return true;
}

int CTable::getElement(int index, bool *p_success) const {
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


void CTable::copyOfTable(const CTable &otherTable) {
    int newSize = otherTable.getSize();
    delete [] m_array;
    m_size = newSize;

    // Create new array with length equal to otherTable's array
    int *newArray = new int[newSize];

    // Free memory and assign a new array
    m_array = newArray;

    bool success;
    // Copy elements
    for (int i = 0; i < newSize; i++) {
        newArray[i] = otherTable.getElement(i, &success);
        if (!success) {
            cerr << COPY_OF_TABLE_FAILED << endl;
        }
    }
}
CTable CTable::clone(bool *p_success) {
    return CTable(*this);
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

string CTable::getName() const {
    return m_name;
}

void CTable::changeName(std::string newName) {
    m_name = newName;
}

string CTable::toString() {
    string stringRepresentation = m_name + " ";
    for (int i = 0; i < m_size - 1; i++) {
        std::string stringOfNumber = to_string(m_array[i]) + ", ";
        stringRepresentation.append(stringOfNumber);
    }
    // Append last element without comma and space
    stringRepresentation.append(to_string(m_array[m_size - 1]));
    return stringRepresentation;
}


