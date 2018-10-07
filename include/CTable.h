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
        bool checkIfIndexOutOfBorder(int index) const;
        int *m_array;
        std::string m_name;
        int m_size;

    public:
        CTable();
        CTable(std::string name, int tableLen);
        CTable(const CTable & otherTable);
        ~CTable();
        void changeTableLength(int newLength);
        void setElement(int index, int element, bool *p_success);
        int getElement(int index, bool *p_success) const;
        CTable clone(bool *p_success);
        void copyOfTable(const CTable &otherTable);
        void changeName(std::string newName);
        std::string toString();
        int getSize() const;
        std::string getName() const;
};

#endif CTABLE_CTABLE_H
