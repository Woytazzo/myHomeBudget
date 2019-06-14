#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

class AdditionalMethods
{

public:
    string convertIntToString (int number);
    string changeComaToDot(string number);
    string convertFloatToString (float number);
    int convertDateFromStringToIntWithoutPauses(string dateWithPauses);
    string convertDateFromIntToStringAndAddPauses(int dateWithoutPauses);
};

#endif // ADDITIONALMETHODS_H

