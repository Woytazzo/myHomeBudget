#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "Markup.h"
#include "AdditionalMethods.h"
#include "Transaction.h"

using namespace std;

class File
{
    AdditionalMethods additionalMethods;
    CMarkup xml;
public:
    vector <Transaction> loadTransactionsFromFile(int idOfLoggedUser, string fileName);
    void ifFileOpens(CMarkup xml);
    vector <Transaction> convertTransactionsDataFromXmlToVector(int idOfLoggedUser);
    void saveLastTransactionToFile(Transaction transaction, int idOfLoggedUser, string fileName);
};
#endif
