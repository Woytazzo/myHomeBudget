#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "Transaction.h"
#include "AdditionalMethods.h"
#include "Markup.h"
#include "File.h"

using namespace std;

class FileWithExpenses :public File
{
    const string NAME_OF_FILE_WITH_EXPENSES;
    public:
    FileWithExpenses(string FILEWITHEXPENSES) : NAME_OF_FILE_WITH_EXPENSES(FILEWITHEXPENSES){};
};
#endif
