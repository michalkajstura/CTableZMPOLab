#ifndef CTABLE_CTWONUMBERSMANAGER_H
#define CTABLE_CTWONUMBERSMANAGER_H

#include <iostream>

class CTwoNumbersManager {
    private:
        int m_liczba1, m_liczba2;

    public:
    CTwoNumbersManager();
    int getLiczba1() const;
    void setLiczba1(int liczba1);
    int getLiczba2() const;
    void setLiczba2(int liczba2);
    void reset();
    void add();
    void subtract();
};


#endif //CTABLE_CTWONUMBERSMANAGER_H
