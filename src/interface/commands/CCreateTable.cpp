#include "../../../include/CCreateTable.h"

using namespace std;

const string ERROR_INDEX_OF_TABLE = "Wpisano niepoprawny indeks tablicy.";
const string SIZE_MESSAGE = "Rozmiar: ";

void CCreateTable::runCommand() {
    string tableName;

    // Get table name and validate
    cout << "Nazwa: ";
    cin >> tableName;
    cout << "\n";

    // Get size and validate
    string tableSizeString;
    cout << SIZE_MESSAGE;
    cin >> tableSizeString;
    cout << "\n";

    int tableSize;

    // Check if size is integer greater then 0
    if (stringUtils::isInt(tableSizeString)
        && stoi(tableSizeString) > 0) {
        tableSize = stoi(tableSizeString);

        // Create new table and add it to list
        CTable *table = new CTable(tableName, tableSize);
        getTableManager()->addTable(table);
    } else {
        cout << ERROR_INDEX_OF_TABLE << endl;
        inputUtils::waitForUser();
    }
}
