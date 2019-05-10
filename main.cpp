#include <ctime>
#include <string>
#include <iostream>
#include "Markup.h"
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "PersonalBudget.h"
//#include "UserManager.h"
//#include "AccountManager.h"
//#include "FileWithUsers.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Incomes.xml", "Expanses.xml", "Users.xml");
    //FileWithIncomes fileWithIncomes("Incomes.xml");
    //vector <Transaction> incomes = fileWithIncomes.loadIncomesFromFile(8);
    personalBudget.mainMenus();
    return 0;
}
/*
struct Date
{
    int day;
    int month;
    int year;
};

struct MyStruct
{
    int date;
    string stringValue;

    MyStruct(int d, const string& s) : date(d), stringValue(s) {}
};

struct less_than_date
{
    inline bool operator() (const MyStruct& struct1, const MyStruct& struct2)
    {
        return (struct1.date < struct2.date);
    }
};
void sortingVectorByDate()
{
vector < MyStruct > vec;

vec.push_back(MyStruct(4, "test"));
vec.push_back(MyStruct(3, "a"));
vec.push_back(MyStruct(2, "is"));
vec.push_back(MyStruct(1, "this"));

sort(vec.begin(), vec.end(), less_than_date());

cout<<vec[3].date<<endl;
}

Date getYearMonthDayFromWholeDate(string dateByUser)
{
    //string date="";
    string temp="";
    int pauseCounter=0;
    Date date;

    //date = "2019-02-23";

    for (int i=0; i<dateByUser.size(); i++)
    {

        if (dateByUser[i]==45)
        {
            i++;
            pauseCounter++;
            if (pauseCounter==1)
            {
                date.year=atoi(temp.c_str());
                temp="";
            }
            else if (pauseCounter==2)
            {
                date.month=atoi(temp.c_str());
                temp="";
            }
        }
        temp+=dateByUser[i];
    }
    date.day=atoi(temp.c_str());

    return date;
}
int giveAmountOfDaysInMonth(Date date)
{
    int days;

    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
		days = 30;

	else if (date.month == 02)
	{
		bool leapyear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);

		if (leapyear == 0)
				days = 28;
		else
				days = 29;
	}

	else
	days = 31;

return days;
}




void choosingPeriodOfTimeForCalculation()
{

    struct date {
    int year, month, day;
    };
    //generujemy losowe liczby które udają nasze wpisane wczesniej daty
    date transactions[10];
    for (int i=0; i<10; i++)
    {
        transactions[i].year = rand() % 5 + 2010;
        transactions[i].month = rand() % 12 + 1;
        transactions[i].day = rand() % 28 + 1;
    }

    cout<<transactions[3].year<<"-"<<transactions[3].month<<"-"<<transactions[3].day<<endl;
    cout<<transactions[7].year<<"-"<<transactions[7].month<<"-"<<transactions[7].day<<endl;
    cout<<transactions[1].year<<"-"<<transactions[1].month<<"-"<<transactions[1].day<<endl;

    //podajemy datę początkową i koncową okresu do obliczenia bilansu

    //ostatecznie w programie musi sie to zaczac od if-a dotyczącego userId

    // stopniowany if (rok-miesiac-dzien) ze znakiem >= data początkowa, kiedy spelnia to dodajemy do vectora

    //potem podobnie tylko <= data koncowa i jesli nie spełnia to usuwamy z wektora i mamy kompletny wektor

}

int howManyDaysInAMonth()
{
    cout << "Enter a Date to obtain how many days are in a month:" << endl;
	int year = 0;
	int month = 0;
	int days;
	cout << "Enter Year: ";
	cin >> year;
	cout << "Enter Month: ";
	cin >> month;


	if (month == 4 || month == 6 || month == 9 || month == 11)
		days = 30;

	else if (month == 02)
	{
		bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (leapyear == 0)
				days = 28;
		else
				days = 29;
	}

	else
	days = 31;

return days;
}

*/
