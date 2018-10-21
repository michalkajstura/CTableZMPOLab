#include "../../../include/CCreateTable.h"

using namespace std;

const string ERROR_INDEX_OF_TABLE = "Wpisano niepoprawny indeks tablicy.";

CCreateTable::CCreateTable(CTableManager *manager) : CCTableCommand(manager){
    m_arguments_info = "<nazwa> <długość>";
    m_arguments_number = 2;
}

void CCreateTable::runCommand(vector<string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string tableName = arguments.at(0);
    string tableSizeString = arguments.at(1);

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
