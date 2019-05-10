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
