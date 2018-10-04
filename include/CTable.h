#ifndef CTABLE_CTABLE_H
#define CTABLE_CTABLE_H

#define DEFAULT_SIZE 10
#define DEFAULT_NAME "Tablica"

#include <string>

class CTable {
    private:
        int *m_array;
        std::string m_name;
        int m_size;

    public:
        CTable();
        CTable(std::string name, int tableLen);
        ~CTable();
        void changeTableLength(int newLength);
        bool setElement(int index, int element);
        int getElement(int index, int *success);
        CTable clone();
        void copyOfTable(CTable table);
        

};


#endif CTABLE_CTABLE_H
