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
#include "File.h"

using namespace std;

class FileWithIncomes :public File
{
    const string NAME_OF_FILE_WITH_INCOMES;
    public:
    FileWithIncomes(string FILEWITHINCOMES) : NAME_OF_FILE_WITH_INCOMES(FILEWITHINCOMES){};
};
#endif
