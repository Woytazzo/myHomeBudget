#ifndef FILEWITHEXPANSES_H
#define FILEWITHEXPANES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "Transaction.h"
#include "AdditionalMethods.h"
#include "Markup.h"

using namespace std;

class FileWithExpanses
{
    const string NAME_OF_FILE_WITH_EXPANSES;
    AdditionalMethods additionalMethods;
    CMarkup xml;
public:
    FileWithExpanses(string FILEWITHEXPANSES) : NAME_OF_FILE_WITH_EXPANSES(FILEWITHEXPANSES){};
    void saveExpansesToFile(vector <Transaction> expanses, int idOfLoggedUser);
    vector <Transaction> loadExpansesFromFile(int idOfLoggedUser);
    void ifFileOpens(CMarkup xml);
    vector <Transaction> convertExpansesDataFromXmlToVector(int idOfLoggedUser);
    void saveLastExpanseToFile(Transaction expanse, int idOfLoggedUser);

};
#endif
