#ifndef CTABLE_CTABLE_H
#define CTABLE_CTABLE_H

#define DEFAULT_SIZE 10
#define DEFAULT_NAME "Tablica"
#define DEFAULT_VALUE 0

#include <string>

class CTable {
    private:
        void fillArrayWithDefaultValue();
        int *m_array;
        std::string m_name;
        int m_size;

    public:
        CTable();
        CTable(std::string name, int tableLen);
        CTable(CTable &otherTable, bool *success);
        ~CTable();
        void changeTableLength(int newLength);
        bool setElement(int index, int element);
        int getElement(int index, bool *success);
        CTable clone();
        void copyOfTable(CTable otherTable, bool *success);
        std::string toString();
        int getSize();
        std::string getName();
};


#endif CTABLE_CTABLE_H
