#include "CChangeTableLength.h"

using namespace std;

const string LENGTH_ERROR = "Niepoprawna długość";

CChangeTableLength::CChangeTableLength(CTableManager *manager) : CCTableCommand(manager) {
    m_arguments_info = "<length>";
    m_arguments_number = 1;
}

void CChangeTableLength::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;

    string userInputLength = arguments.at(0);

    if (stringUtils::isInt(userInputLength) && stoi(userInputLength) >= 0) {
        int length = stoi(userInputLength);
        getTableManager()->getCurrentTable()->changeTableLength(length);
    } else {
        cout << LENGTH_ERROR << endl;
    }
}
