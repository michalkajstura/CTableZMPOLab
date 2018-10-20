#include "CChangeTableLength.h"

using namespace std;

const string LENGTH_MESSAGE = "Podaj długość: ";
const string LENGTH_ERROR = "Niepoprawna długość";

void CChangeTableLength::runCommand() {
    string userInputLength;
    cout << LENGTH_MESSAGE;
    cin >> userInputLength;

    if (stringUtils::isInt(userInputLength) && stoi(userInputLength) >= 0) {
        int length = stoi(userInputLength);
        getTableManager()->getCurrentTable()->changeTableLength(length);
    } else {
        cout << LENGTH_ERROR << endl;
    }
}
