#include "commands/CSetTableElement.h"

using namespace std;

const string INDEX_ERROR= "Niepoprawny indeks!";
const string VALUE_ERROR = "Niepoprawna wartość!";

CSetTableElement::CSetTableElement(CTableManager *manager) : CCTableCommand(manager){
    m_arguments_info = "<index> <element>";
    m_arguments_number = 2;
}

void CSetTableElement::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string userInputIndex = arguments.at(0);
    string userInputValue= arguments.at(1);

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