#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);


    int getDay();
     int getMonth();
      int getYear();
};

#endif
