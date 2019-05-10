#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "Markup.h"
#include "AdditionalMethods.h"
#include "Transaction.h"

using namespace std;

class FileWithIncomes
{
    const string NAME_OF_FILE_WITH_INCOMES;
    AdditionalMethods additionalMethods;
    CMarkup xml;
public:
    FileWithIncomes(string FILEWITHINCOMES) : NAME_OF_FILE_WITH_INCOMES(FILEWITHINCOMES){};
    void saveIncomesToFile(vector <Transaction> incomes, int idOfLoggedUser);
    vector <Transaction> loadIncomesFromFile(int idOfLoggedUser);
    void ifFileOpens(CMarkup xml);
    vector <Transaction> convertIncomesDataFromXmlToVector(int idOfLoggedUser);
    void saveLastIncomeToFile(Transaction income, int idOfLoggedUser);
};
#endif

