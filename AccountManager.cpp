#include "AccountManager.h"

void AccountManager::showMenu()
{
    cout<<"Witaj. To Twoj osobisty budzet. Co chcesz teraz zrobic?"<<endl;
    cout<<"1. dodaj przychod"<<endl;
    cout<<"2. dodaj wydatek"<<endl;
    cout<<"3. wyswietl bilans"<<endl;
    cout<<"4. zmiana hasla"<<endl;
    cout<<"5. wyloguj sie"<<endl;
}

void AccountManager::showBalanceInnerMenu()
{
    cout<<"Z jakiego okresu bilans chcesz wyswietlic?"<<endl;
    cout<<"1. biezacego miesiaca"<<endl;
    cout<<"2. poprzedniego miesiaca"<<endl;
    cout<<"3. wybranego okresu"<<endl;
}

int AccountManager::getAcctualYearFromSystem()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    return (now->tm_year + 1900);
}
int AccountManager::getAcctualMonthFromSystem()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    return (now->tm_mon + 1);
}
int AccountManager::getAcctualDayFromSystem()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
         return (now->tm_mday);
}

string AccountManager::getTodaysDateFromSystem()
{
    int day, month, year;

    day=getAcctualDayFromSystem();
    month=getAcctualMonthFromSystem();
    year=getAcctualYearFromSystem();

    string dayConverted, monthConverted, yearConverted, dateFromSystem;

    dayConverted=additionalMethods.convertIntToString(day);
    dayConverted=addZeroIfTheresOnlyOneNumber(dayConverted);

    monthConverted=additionalMethods.convertIntToString(month);
    monthConverted=addZeroIfTheresOnlyOneNumber(monthConverted);

    yearConverted=additionalMethods.convertIntToString(year);

    dateFromSystem=yearConverted+"-"+monthConverted+"-"+dayConverted;
    return dateFromSystem;
}

string AccountManager::addZeroIfTheresOnlyOneNumber(string number)
{
    if(number.size()==1)
    number="0"+number;
    return number;
}
void AccountManager::getYearMonthDayFromWholeDate(string dateByUser)
{
    //string date="";
    string temp="";
    int pauseCounter=0;

    //date = "2019-02-23";

    for (int i=0; i<dateByUser.size(); i++)
    {

        if (dateByUser[i]==45)
        {
            i++;
            pauseCounter++;
            if (pauseCounter==1)
            {
                dateWithSeparationForYearMonthDay.setYear(atoi(temp.c_str()));
                temp="";
            }
            else if (pauseCounter==2)
            {
                dateWithSeparationForYearMonthDay.setMonth(atoi(temp.c_str()));
                temp="";
            }
        }
        temp+=dateByUser[i];
    }
    dateWithSeparationForYearMonthDay.setDay(atoi(temp.c_str()));
}
int AccountManager::giveAmountOfDaysInMonth(Date date)
{
    int days;

    if (date.getMonth() == 4 || date.getMonth() == 6 || date.getMonth() == 9 || date.getMonth() == 11)
		days = 30;

	else if (date.getMonth() == 02)
	{
		bool leapyear = (date.getYear() % 4 == 0 && date.getYear() % 100 != 0) || (date.getYear() % 400 == 0);

		if (leapyear == 0)
				days = 28;
		else
				days = 29;
	}

	else
	days = 31;

return days;
}

bool AccountManager::ifDateIsCorrect(string dateByUser)
{
    if (dateByUser.size()==10)
    {
        for (int i=0; i<dateByUser.size(); i++)
        {
            if (i<4 || (i>4 && i<7) || i>7)
            {
                if (dateByUser[i]<48 || dateByUser[i]>57)
                {
                    return false;
                }
            }
            if (i==4 || i==7)
            {
                if (dateByUser[i]!=45)
                return false;
            }
        }
    }
    else
    {
        //cout<<"nieodpowiednia ilosc znakow"<<endl;
        return false;
    }

    getYearMonthDayFromWholeDate(dateByUser);
    if (dateWithSeparationForYearMonthDay.getMonth()<1 || dateWithSeparationForYearMonthDay.getMonth()>12)
        return false;
    int amountOfDaysInTheMonth=giveAmountOfDaysInMonth(dateWithSeparationForYearMonthDay);
    if (dateWithSeparationForYearMonthDay.getDay()<1 || dateWithSeparationForYearMonthDay.getDay()>amountOfDaysInTheMonth)
        return false;
    return true;
}

string AccountManager::setDateManuallyByUser()
{
    dateByUser="0000-00-00";
    while(ifDateIsCorrect(dateByUser)!=true)
    {
        cout<<"podaj date transakcji w formacie rrrr-mm-dd"<<endl;
    cin>>dateByUser;
    if(ifDateIsCorrect(dateByUser)!=true)
        cout<<"blednie wprowadzona data"<<endl;
    }


    return dateByUser;
}

string AccountManager::getInfoAboutTransaction()
{
    string textByUser;
    cout<<"czego dotyczy transakcja ?"<<endl;
    cin.ignore();
    getline(cin, textByUser);
    return textByUser;
}

float AccountManager::getAmountOfMoney()
{
    string moneyByUser;
    cout<<"Podaj wysokosc transakcji: "<<endl;
    cin>>moneyByUser;
    moneyByUser=additionalMethods.changeComaToDot(moneyByUser);
    float textToFloat = atof(moneyByUser.c_str());
    return textToFloat;
}

void AccountManager::addTransaction()
{
    system("cls");
    cout<<"DODAWANIE TRANSAKCJI:"<<endl;
     int choiceOfUser=0;

    cout<<"czy transakcja dotyczy dnia dzisiejszego?"<<endl;
    cout<<"1. TAK"<<endl;
    cout<<"2. NIE"<<endl;
    cin>>choiceOfUser;

    transaction.setTransactionId(++lastTransactionId);//tutaj ustawic dynamiczne przypisywanie
    switch (choiceOfUser)
    {
    case 1:
        transaction.setDateOfTransaction(getTodaysDateFromSystem());
        break;
    case 2:
        transaction.setDateOfTransaction(setDateManuallyByUser());
        break;
    }
    transaction.setTransactionDescription(getInfoAboutTransaction());
    transaction.setAmountOfMoneyInTransaction(getAmountOfMoney());//tutaj z funkcją zmieniającą przecinek w kropkę
}

void AccountManager::addIncome()
{
    system("cls");
    cout<<"DODAJ PRZYCHOD"<<endl;
    addTransaction();
    incomes.push_back(transaction);
    fileWithIncomes.saveLastTransactionToFile(transaction, idOfLoggedUser, "Incomes.xml");
}

void AccountManager::addExpense()
{
    system("cls");
    cout<<"DODAJ WYDATEK"<<endl;
    addTransaction();
    expenses.push_back(transaction);
    fileWithExpenses.saveLastTransactionToFile(transaction, idOfLoggedUser, "Expenses.xml");
}

int AccountManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
}

struct Date AccountManager::divideDateToDayMonthYear(string date)
{
    Date sDate;
    sDate.setYear(atoi((date.substr(0,4)).c_str()));
    sDate.setMonth(atoi((date.substr(5,2)).c_str()));
    sDate.setDay(atoi((date.substr(8,2)).c_str()));
    return sDate;
}

void AccountManager::getIncomesFromSpecificPeriod(Date beginningDateToSum, Date endingDateToSum)
{
    Date dateFromIncome;

    incomesInBalance.clear();

    for (int i=0; i<incomes.size(); i++)
    {
        dateFromIncome=divideDateToDayMonthYear(incomes[i].getDateOfTransaction());

        if(dateFromIncome.getYear()>=beginningDateToSum.getYear() &&
            dateFromIncome.getMonth()>=beginningDateToSum.getMonth() &&
            dateFromIncome.getDay()>=beginningDateToSum.getDay() &&
            dateFromIncome.getYear()<=endingDateToSum.getYear() &&
            dateFromIncome.getMonth()<=endingDateToSum.getMonth() &&
            dateFromIncome.getDay()<=endingDateToSum.getDay() )
            incomesInBalance.push_back(incomes[i]);
    }
}
void AccountManager::getExpensesFromSpecificPeriod(Date beginningDateToSum, Date endingDateToSum)
{
    Date dateFromExpense;

    expensesInBalance.clear();

    for (int i=0; i<expenses.size(); i++)
    {
        dateFromExpense=divideDateToDayMonthYear(expenses[i].getDateOfTransaction());

        if(dateFromExpense.getYear()>=beginningDateToSum.getYear() &&
            dateFromExpense.getMonth()>=beginningDateToSum.getMonth() &&
            dateFromExpense.getDay()>=beginningDateToSum.getDay() &&
            dateFromExpense.getYear()<=endingDateToSum.getYear() &&
            dateFromExpense.getMonth()<=endingDateToSum.getMonth() &&
            dateFromExpense.getDay()<=endingDateToSum.getDay() )
            expensesInBalance.push_back(expenses[i]);
    }
}

void AccountManager::printAllIncomesToBalance()
{
    cout<<"PRZYCHODY:"<<endl;
    cout<<"DATA / OPIS / KWOTA"<<endl;
    for(int i=0; i<incomesInBalance.size(); i++)
    {
          cout<<incomesInBalance[i].getDateOfTransaction()<<" / "
          <<incomesInBalance[i].getTransactionDescription()<<" / "
          <<incomesInBalance[i].getAmountOfMoneyInTransaction()<<endl;
    }
    system("pause");
}


void AccountManager::printAllExpensesToBalance()
{
    cout<<"WYDATKI:"<<endl;
    cout<<"DATA / OPIS / KWOTA"<<endl;
    for(int i=0; i<expensesInBalance.size(); i++)
    {
          cout<<expensesInBalance[i].getDateOfTransaction()<<" / "
          <<expensesInBalance[i].getTransactionDescription()<<" / "
          <<expensesInBalance[i].getAmountOfMoneyInTransaction()<<endl;
    }
    system("pause");
}

float AccountManager::sumUpIncomesAndExpensesToBalance()
{
    float balance=0;
    for(int i=0; i<incomesInBalance.size(); i++)
        balance=balance+incomesInBalance[i].getAmountOfMoneyInTransaction();
    for(int i=0; i<expensesInBalance.size(); i++)
        balance=balance-expensesInBalance[i].getAmountOfMoneyInTransaction();
        return balance;
}

void AccountManager::getIncomesOfThisMonth()
{
    string date;
    int month;
    incomesInBalance.clear();

    for(int i=0; i<incomes.size(); i++)
    {
        date=incomes[i].getDateOfTransaction();
        date = date.erase(0,5);
        date = date.erase(2,3);
        month = atoi(date.c_str());

        if (month==getAcctualMonthFromSystem())
        incomesInBalance.push_back(incomes[i]);
    }
}

void AccountManager::getExpensesOfThisMonth()
{
    string date;
    int month;
    expensesInBalance.clear();

    for(int i=0; i<expenses.size(); i++)
    {
        date=expenses[i].getDateOfTransaction();
        date = date.erase(0,5);
        date = date.erase(2,3);
        month = atoi(date.c_str());

        if (month==getAcctualMonthFromSystem())
        expensesInBalance.push_back(expenses[i]);
    }
}

void AccountManager::balanceOfSpecificPeriod(Date date1, Date date2)
{
    system("cls");
    getIncomesFromSpecificPeriod(date1, date2);
    printAllIncomesToBalance();
    cout<<endl;
    getExpensesFromSpecificPeriod(date1, date2);
    printAllExpensesToBalance();
    cout<<endl;
    cout<<"BILANS:"<<endl<<sumUpIncomesAndExpensesToBalance()<<endl;
    system ("pause");
}

void AccountManager::balanceOfThisMonth()
{
    system("cls");
    getIncomesOfThisMonth();
    getExpensesOfThisMonth();
    printAllIncomesToBalance();
    cout<<endl;
    printAllExpensesToBalance();
    cout<<endl;
    cout<<"BILANS:"<<endl<<sumUpIncomesAndExpensesToBalance()<<endl;
    system ("pause");
}

Date AccountManager::chooseOpeningDate()
{
    system("cls");
    string date;
 cout<<"podaj date (w formacie rrrr-mm-dd), od ktorej zaczniemy liczyc bilans"<<endl;
 cin>>date;
 getYearMonthDayFromWholeDate(date);
 return dateWithSeparationForYearMonthDay;
}

Date AccountManager::chooseClosingDate()
{
    system("cls");
    string date;
    cout<<"podaj date (w formacie rrrr-mm-dd), na ktorej skonczymy liczyc bilans"<<endl;
    cin>>date;
    getYearMonthDayFromWholeDate(date);
    return dateWithSeparationForYearMonthDay;
}

void AccountManager::balance()
{
    int choiceOfUser;
    balanceMenu();
    cin>>choiceOfUser;
    switch (choiceOfUser)
    {
    case 1:
        balanceOfThisMonth();
        break;
    case 2:
        balanceOfPreviousMonth();
        break;
    case 3:
        Date date1=chooseOpeningDate();
        Date date2=chooseClosingDate();
        balanceOfSpecificPeriod(date1, date2);
    }

}
void AccountManager::balanceMenu()
{
    system("cls");
    cout<<"JAKI BILANS CHCESZ POLICZYC? WYBIERZ I ZATWIERDZ (ENTER)"<<endl;
    cout<<"1. BILANS BIEZACEGO MIESIACA"<<endl;
    cout<<"2. BILANS POPRZEDNIEGO MIESIACA"<<endl;
    cout<<"3. BILANS WYBRANEGO OKRESU"<<endl;
}

int AccountManager::getLastTransactionId()
{
    lastTransactionId=0;
    for(int i=0; i<incomes.size(); i++)
    {
        if(incomes[i].getTransactionId()>lastTransactionId)
            lastTransactionId=incomes[i].getTransactionId();
    }

    for(int j=0; j<expenses.size(); j++)
    {
        if(expenses[j].getTransactionId()>lastTransactionId)
            lastTransactionId=expenses[j].getTransactionId();
    }
    return lastTransactionId;
}

void AccountManager::getExpensesOfPrevMonth()
{
    string date;
    int month, year;
    expensesInBalance.clear();

    for(int i=0; i<expenses.size(); i++)
    {
        date=expenses[i].getDateOfTransaction();
        date = date.erase(0,5);
        date = date.erase(2,3);
        month = atoi(date.c_str());

        date=expenses[i].getDateOfTransaction();
        date = date.erase(4,6);
        year = atoi(date.c_str());
        if((getAcctualMonthFromSystem()!=1) && getAcctualYearFromSystem()==year)
        {
            if
            (month==(getAcctualMonthFromSystem()-1))
            expensesInBalance.push_back(expenses[i]);
        }
        else
        {
            if((month==12) && (getAcctualYearFromSystem()-1==year))
            expensesInBalance.push_back(expenses[i]);
        }
    }
}

void AccountManager::getIncomesOfPrevMonth()
{
    string date;
    int month, year;
    incomesInBalance.clear();

    for(int i=0; i<incomes.size(); i++)
    {
        date=incomes[i].getDateOfTransaction();
        date = date.erase(0,5);
        date = date.erase(2,3);
        month = atoi(date.c_str());

        date=incomes[i].getDateOfTransaction();
        date = date.erase(4,6);
        year = atoi(date.c_str());
        if((getAcctualMonthFromSystem()!=1) && getAcctualYearFromSystem()==year)
           {
            if(month==(getAcctualMonthFromSystem()-1))
            incomesInBalance.push_back(incomes[i]);
            }
        else
        {
            if((month==12) && (getAcctualYearFromSystem()-1==year))
            incomesInBalance.push_back(incomes[i]);
        }
    }
}

void AccountManager::balanceOfPreviousMonth()
{
    system("cls");
    getIncomesOfPrevMonth();
    getExpensesOfPrevMonth();
    sortingIncomesByDate();
    printAllIncomesToBalance();
    cout<<endl;
    printAllExpensesToBalance();
    cout<<endl;
    cout<<"BILANS:"<<endl<<sumUpIncomesAndExpensesToBalance()<<endl;
    system ("pause");
}


int AccountManager::makePartitionOfIncomes(int p, int r)
{

    int x = atoi((((incomes[p].getDateOfTransaction()).erase(4,1)).erase(6,1)).c_str()); // obieramy x

    int i = p, j = r;
    Transaction w; // i, j - indeksy w tabeli
    while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
    {
        while (atoi((((incomes[j].getDateOfTransaction()).erase(4,1)).erase(6,1)).c_str()) > x) // dopoki elementy sa wieksze od x
            j--;
        while (atoi((((incomes[i].getDateOfTransaction()).erase(4,1)).erase(6,1)).c_str()) < x) // dopoki elementy sa mniejsze od x
            i++;
        if (i < j) // zamieniamy miejscami gdy i < j
        {
            w = incomes[i];
            incomes[i] = incomes[j];
            incomes[j] = w;
            i++;
            j--;
        }
        else // gdy i >= j zwracamy j jako punkt podzialu tablicy
            return j;
    }
}

void AccountManager::quicksort(int p, int r) // sortowanie szybkie
{
int q;
if (p < r)
{
q = makePartitionOfIncomes(p,r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
quicksort(p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
quicksort(q+1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
}
}

void AccountManager::sortingIncomesByDate()
{
    quicksort(0, incomes.size());
}
