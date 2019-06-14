#include "AdditionalMethods.h"

string AdditionalMethods::convertIntToString (int number)
{
  stringstream ss;
ss << number;
string str = ss.str();
return str;
}

string AdditionalMethods::convertFloatToString (float number)
{
  stringstream ss;
ss << number;
string str = ss.str();
return str;
}

string AdditionalMethods::changeComaToDot(string number)
{
    for(int i=0; i<number.size(); i++)
    {
        if(number[i]==44)
            number[i]=46;
    }
    return number;
}

int AdditionalMethods::convertDateFromStringToIntWithoutPauses(string dateWithPauses)
{
    dateWithPauses.erase(4,1);
    dateWithPauses.erase(6,1);
    int dateWithoutPausesToInt=atoi(dateWithPauses.c_str());
    return dateWithoutPausesToInt;
}

string AdditionalMethods::convertDateFromIntToStringAndAddPauses(int dateWithoutPauses)
{
    string dateWithPauses=convertIntToString(dateWithoutPauses);
    dateWithPauses.insert(4,"-");
    dateWithPauses.insert(7,"-");
    return dateWithPauses;
}
