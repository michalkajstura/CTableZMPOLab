#include "CSetTableElement.h"

using namespace std;

const string INDEX_MESSAGE = "Podaj indeks: ";
const string VALUE_MESSAGE = "Podaj wartość: ";
const string INDEX_ERROR= "Niepoprawny indeks!";
const string VALUE_ERROR = "Niepoprawna wartość!";

void CSetTableElement::runCommand() {
    // Get input from user
    string userInputIndex, userInputValue;
    cout << INDEX_MESSAGE;
    cin >> userInputIndex;
    cout << VALUE_MESSAGE;
    cin >> userInputValue;

    // Validate input
    if (!stringUtils::isInt(userInputIndex))
        cout << INDEX_ERROR << endl;
    else if (!stringUtils::isInt(userInputValue))
        cout << VALUE_ERROR << endl;
    else {
        int index = stoi(userInputIndex);
        int value = stoi(userInputValue);

        bool success;
        getTableManager()->getCurrentTable()->setElement(index, value, &success);
        if (!success)
            cout << INDEX_ERROR << endl;
    }
}