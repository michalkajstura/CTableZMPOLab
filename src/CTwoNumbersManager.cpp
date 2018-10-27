#include "CTwoNumbersManager.h"

using namespace std;

CTwoNumbersManager::CTwoNumbersManager() {
    m_liczba1 = 0;
    m_liczba2 = 0;
}

int CTwoNumbersManager::getLiczba1() const {
    return m_liczba1;
}

void CTwoNumbersManager::setLiczba1(int liczba1) {
    m_liczba1 = liczba1;
}

int CTwoNumbersManager::getLiczba2() const {
    return m_liczba2;
}

void CTwoNumbersManager::setLiczba2(int liczba2) {
    m_liczba2 = liczba2;
}

void CTwoNumbersManager::reset() {
    m_liczba1 = 0;
    m_liczba2 = 0;
}

void CTwoNumbersManager::add() {
    cout << m_liczba1 + m_liczba2 << endl;
}

void CTwoNumbersManager::subtract() {
    cout << m_liczba1 - m_liczba2 << endl;
}
