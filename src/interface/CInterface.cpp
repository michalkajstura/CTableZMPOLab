#include "../../include/CInterface.h"
#include "../../include/CTable.h"

using namespace std;

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
        cout << '\n' << "Naciśnij enter by kontynuować";
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
        case 1: createTable(); break;
        case 2: displayAllTables(); break;
        case 3: goToTable(); break;
        case 4: deleteAllTables(); break;
        case 5: quit(); break;
        default: cerr << "Error occurred in processPrimaryMenu" << endl;
    }
}

void CInterface::processTableMenu(int userInput) {
    switch (userInput) {
        case 1: printTableLength(); break;
        case 2: changeTableName(); break;
        case 3: changeTableLength(); break;
        case 4: cloneTable(); break;
        case 5: displayTable(); break;
        case 6: setTableElement(); break;
        case 7: deleteTable(); break;
        case 8: backToPrimaryMenu(); break;
        default: cerr << "Error occurred in processTableMenu" << endl;
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
        cout << "Niepoprawna wartość!" << endl;
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
        cout << "Wpisano niepoprawną nazwę tablicy. Ustawiam nazwę domyślną" << endl;
        tableName = DEFAULT_NAME;
        waitForUser();
    }

    // Get size and validate
    string tableSizeString;
    cout << "Rozmiar: ";
    cin >> tableSizeString;
    cout << "\n";

    int tableSize;

    // Check if size is greater then 0
    if (validateInput(tableSizeString, INT32_MAX)) {
        tableSize = stoi(tableSizeString);
    } else {
        cout << "Wpisano niepoprawny rozmiar tablicy. Ustawiam rozmiar domyślny" << endl;
        tableSize = DEFAULT_SIZE;
        waitForUser();
    }

    // Create new table and add it to list
    CTable *table = new CTable(tableName, tableSize);
    m_tables.push_back(table);
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
    cout << "Tablica: ";
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
        cout << "Niepoprawny indeks tablicy!" << endl;
        waitForUser();
    }
}

void CInterface::quit() {
    m_exitLoop = true;
}

// Table menu functions
void CInterface::printTableLength() {
    cout << "Rozmiar: ";
    cout<< m_currentlyOperatedTable->getSize() << endl;
}

void CInterface::changeTableName() {
    string newName;
    cout << "Nowa nazwa: ";
    cin >> newName;
    if (!newName.empty()) {
        m_currentlyOperatedTable->changeName(newName);
    } else {
        cout << "Niepoprawna nazwa" << endl;
        waitForUser();
    }
}

void CInterface::changeTableLength() {
    string newLengthString;
    cout << "Nowa długość: ";
    cin >> newLengthString;
    if (stringUtils::isInt(newLengthString)) {
        int newLenghtInt = stoi(newLengthString);
        if (newLenghtInt >= 0) {
            m_currentlyOperatedTable->changeTableLength(newLenghtInt);
        } else {
            cout << "Długość tablicy nie może być mniejsza od 0!" << endl;
        }
    } else {
        cout << "Niepoprawna długość tablicy!" << endl;
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
    cout << "Indeks: ";
    cin >> indexString;

    string valueString;
    cout << "Wartość: ";
    cin >> valueString;

    // Validate value
    if (stringUtils::isInt(valueString)) {
        int valueInt = stoi(valueString);
        bool success;
        int indexInt = stoi(indexString);
        m_currentlyOperatedTable->setElement(indexInt, valueInt, &success);
        if (!success) {
            cout << "Niepoprawny index!" << endl;
            waitForUser();
        }
    } else {
        cout << "Niepoprawna wartość!" << endl;
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
