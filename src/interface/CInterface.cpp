#include "../../include/CInterface.h"
#include "../../include/CTable.h"

using namespace std;

const int PRIMARY_MENU = 0;
const int TABLE_MENU = 1;
const int CREATE_TABLE = 1;
const int DISPLAY_ALL_TABLES = 2;
const int GO_TO_TABLE = 3;
const int DELETE_ALL_TABLES = 4;
const int QUIT = 5;
const int DEFAULT_SIZE = 10;
const int PRINT_TABLE_LENGTH = 1;
const int CHANGE_TABLE_NAME = 2;
const int CHANGE_TABLE_LENGTH = 3;
const int CLONE_TABLE = 4;
const int DISPLAY_TABLE = 5;
const int SET_TABLE_ELEMENT = 6;
const int DELETE_TABLE = 7;
const int DOUBLE_ARRAY = 8;
const int BACK_TO_PRIMARY_MENU = 9;
const string DEFAULT_NAME = "Tablica";
const string ERROR_PRIMARY_MENU = "Error occurred in processPrimaryMenu";
const string ERROR_TABLE_MENU = "Error occurred in processTableMenu";
const string ERROR_NAME_OF_TABLE = "Wpisano niepoprawną nazwę tablicy.";
const string ERROR_INDEX_OF_TABLE = "Wpisano niepoprawny indeks tablicy.";
const string ERROR_LENGTH_OF_TABLE = "Wpisano niepoprawną długość tablicy.";
const string ERROR_VALUE= "Wpisano niepoprawną wartość.";
const string PRESS_ENTER = "Naciśnij enter by kontynuować";
const string VALUE_MESSAGE = "Wartość: ";
const string INDEX_MESSAGE = "Indeks: ";
const string NEW_LENGTH_MESSAGE = "Nowa długość: ";
const string NEW_NAME_MESSAGE = "Nowa nazwa: ";
const string SIZE_MESSAGE = "Rozmiar: ";

CInterface::CInterface(){
    m_currentMenu = PRIMARY_MENU;
    m_menu = CPrimaryMenu();
    m_exitLoop = false;
}

CInterface::~CInterface(){
    deleteAllTables();
}


void CInterface::showMenu() {
    m_menu.showMenu();
}

void CInterface::waitForUser() {
    cin.ignore();
    do
    {
        cout << '\n' << PRESS_ENTER;
    } while (cin.get() != '\n');
}

void CInterface::clearScreen() {
    cout << string(100, '\n'); // clear
}

string CInterface::getUserInput() {
    cout << ": ";
    string userInput;
    cin >> userInput;
    return userInput;
}

bool CInterface::validateInput(string userInput, int rangeOfInput) {

     //First check if user input is a string
     if (stringUtils::isInt(userInput)) {
         int inputInt = stoi(userInput);

         // Check if userInput is in range
         bool isInRange = inputInt > 0 && inputInt <= rangeOfInput;
         return isInRange;
     }
    return false;
}

void CInterface::processPrimaryMenu(int userInput) {
    switch (userInput) {
        case CREATE_TABLE: createTable(); break;
        case DISPLAY_ALL_TABLES: displayAllTables(); break;
        case GO_TO_TABLE: goToTable(); break;
        case DELETE_ALL_TABLES: deleteAllTables(); break;
        case QUIT: quit(); break;
        default: cerr << ERROR_PRIMARY_MENU << endl;
    }
}

void CInterface::processTableMenu(int userInput) {
    switch (userInput) {
        case PRINT_TABLE_LENGTH: printTableLength(); break;
        case CHANGE_TABLE_NAME: changeTableName(); break;
        case CHANGE_TABLE_LENGTH: changeTableLength(); break;
        case CLONE_TABLE: cloneTable(); break;
        case DISPLAY_TABLE: displayTable(); break;
        case SET_TABLE_ELEMENT: setTableElement(); break;
        case DELETE_TABLE: deleteTable(); break;
        case DOUBLE_ARRAY: doubleArray(); break;
        case BACK_TO_PRIMARY_MENU: backToPrimaryMenu(); break;
        default: cerr << ERROR_TABLE_MENU << endl;
    }
}

void CInterface::processInput(string userInput) {
    bool inputIsCorrect = validateInput(userInput, m_menu.numberOfMenuItems());
    if (inputIsCorrect) {
        int userInputInt = stoi(userInput);
        if (m_currentMenu == PRIMARY_MENU)
            processPrimaryMenu(userInputInt);
        else
            processTableMenu(userInputInt);
    } else {
        cout << ERROR_VALUE << endl;
        waitForUser();
    }
}


// Primary menu functions
void CInterface::createTable() {
    string tableName;

    // Get table name and validate
    cout << "Nazwa: ";
    cin >> tableName;
    cout << "\n";

    if (tableName.empty()) {
        cout << ERROR_NAME_OF_TABLE << endl;
        tableName = DEFAULT_NAME;
        waitForUser();
    }

    // Get size and validate
    string tableSizeString;
    cout << SIZE_MESSAGE;
    cin >> tableSizeString;
    cout << "\n";

    int tableSize;

    // Check if size is greater then 0
    if (validateInput(tableSizeString, INT32_MAX)) {
        tableSize = stoi(tableSizeString);

        // Create new table and add it to list
        CTable *table = new CTable(tableName, tableSize);
        m_tables.push_back(table);
    } else {
        cout << ERROR_INDEX_OF_TABLE << endl;
        waitForUser();
    }
}

void CInterface::displayAllTables() {
    for(int i = 0; i < m_tables.size(); i++) {
        cout << i + 1;
        cout << ". " + m_tables.at(i)->toString() << endl;
    }
    waitForUser();
}

void CInterface::deleteAllTables() {
    vector<CTable*>::iterator iter;
    for (iter = m_tables.begin(); iter != m_tables.end(); iter++) {
        delete (*iter);
    }
    m_tables.clear();
}

void CInterface::goToTable() {
    string tableNumberString;
    cout << DEFAULT_NAME + ": ";
    cin >> tableNumberString;

    // Validate number
    if (validateInput(tableNumberString, m_tables.size())) {
        int tableNumberInt = stoi(tableNumberString);

        // Decrement the value because menu is displayed from 1.
        tableNumberInt--;

        // Update table we currently working on
        m_currentlyOperatedTable = m_tables.at(tableNumberInt);

        // Update menus
        m_currentMenu = TABLE_MENU;
        m_menu = CTableMenu();

    } else {
        cout << ERROR_INDEX_OF_TABLE << endl;
        waitForUser();
    }
}

void CInterface::quit() {
    m_exitLoop = true;
}

// Table menu functions
void CInterface::printTableLength() {
    cout << SIZE_MESSAGE;
    cout<< m_currentlyOperatedTable->getSize() << endl;
    waitForUser();
}

void CInterface::changeTableName() {
    string newName;
    cout << NEW_NAME_MESSAGE;
    cin >> newName;
    if (!newName.empty()) {
        m_currentlyOperatedTable->changeName(newName);
    } else {
        cout << ERROR_NAME_OF_TABLE << endl;
        waitForUser();
    }
}

void CInterface::changeTableLength() {
    string newLengthString;
    cout << NEW_LENGTH_MESSAGE;
    cin >> newLengthString;
    if (stringUtils::isInt(newLengthString)) {
        int newLenghtInt = stoi(newLengthString);
        if (newLenghtInt >= 0) {
            m_currentlyOperatedTable->changeTableLength(newLenghtInt);
        } else {
            cout << ERROR_LENGTH_OF_TABLE << endl;
        }
    } else {
        cout << ERROR_LENGTH_OF_TABLE << endl;
        waitForUser();
    }
}

void CInterface::cloneTable() {
    CTable *clonedTable = new CTable(*m_currentlyOperatedTable);
    m_tables.push_back(clonedTable);
}

void CInterface::displayTable() {
    cout << m_currentlyOperatedTable->toString() << endl;
    waitForUser();
}

void CInterface::setTableElement() {

    // Get index and value
    string indexString;
    cout << INDEX_MESSAGE;
    cin >> indexString;

    string valueString;
    cout << VALUE_MESSAGE;
    cin >> valueString;

    // Validate value
    if (stringUtils::isInt(valueString)) {
        int valueInt = stoi(valueString);
        bool success;
        int indexInt = stoi(indexString);
        m_currentlyOperatedTable->setElement(indexInt, valueInt, &success);
        if (!success) {
            cout << ERROR_INDEX_OF_TABLE << endl;
            waitForUser();
        }
    } else {
        cout << ERROR_VALUE << endl;
        waitForUser();
    }
}

void CInterface::deleteTable() {
    vector<CTable*>::iterator iter = m_tables.begin();
    while (iter != m_tables.end() &&  *iter != m_currentlyOperatedTable) iter++;

    // Delete CTable object and erase pointer from m_tables
    delete (*iter);
    m_tables.erase(iter);

    backToPrimaryMenu();
}

void CInterface::backToPrimaryMenu() {
    m_currentMenu = PRIMARY_MENU;
    m_menu = CPrimaryMenu();
}

void CInterface::run() {
    while(!m_exitLoop) {
        clearScreen();
        showMenu();
        string userInput = getUserInput();
        processInput(userInput);
    }
}

void CInterface::doubleArray() {
    m_currentlyOperatedTable->doubleArray();
}
