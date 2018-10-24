#include "commands/CDeleteTable.h"

using namespace std;

const string INVALID_INDEX_ERROR = "Podana tabela nie znajduje się w liście";

CDeleteTable::CDeleteTable(CTableManager *manager) : CCTableCommand(manager) {
    m_arguments_info = "<number>";
    m_arguments_number = 1;
}

void CDeleteTable::runCommand(std::vector<std::string> arguments) {
    if (!validaterNumberOfArguments(arguments.size())) return;
    string userInput = arguments.at(0);
    if(stringUtils::isInt(userInput)) {
        getTableManager()->deleteTable(stoi(userInput));
    } else {
        cerr << INVALID_INDEX_ERROR << endl;
    }
}
