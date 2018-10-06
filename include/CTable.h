#ifndef CTABLE_CTABLE_H
#define CTABLE_CTABLE_H

#define DEFAULT_SIZE 10
#define DEFAULT_NAME "Tablica"
#define DEFAULT_VALUE 0

#include <iostream>
#include <string>
#include "utils.h"

class CTable {
    private:
        bool checkIfIndexOutOfBorder(int index);
        int *m_array;
        std::string m_name;
        int m_size;

    public:
        CTable();
        CTable(std::string name, int tableLen);
        CTable(CTable &otherTable, bool *p_success);
        ~CTable();
        void changeTableLength(int newLength);
        void setElement(int index, int element, bool *p_success);
        int getElement(int index, bool *p_success);
        CTable clone(bool *p_success);
        void copyOfTable(CTable &otherTable, bool *p_success);
        void changeName(std::string newName);
        std::string toString();
        int getSize();
        std::string getName();
};

#endif CTABLE_CTABLE_H
