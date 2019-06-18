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

int AccountManager::getTodaysDateFromSystem()
{
    int day, month, year;

    day=getAcctualDayFromSystem();
    month=getAcctualMonthFromSystem();
    year=getAcctualYearFromSystem();

    int dateFromSystem;


    dateFromSystem=year*10000+month*100+day;

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

int AccountManager::setDateManuallyByUser()
{
    dateByUser="0000-00-00";
    while(ifDateIsCorrect(dateByUser)!=true)
    {
        cout<<"podaj date transakcji w formacie rrrr-mm-dd"<<endl;
    cin>>dateByUser;
    if(ifDateIsCorrect(dateByUser)!=true)
        cout<<"blednie wprowadzona data"<<endl;
    }

    int dateByUserToInt=additionalMethods.convertDateFromStringToIntWithoutPauses(dateByUser);
    return dateByUserToInt;
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

int AccountManager::addTransaction(int lastTransactionId)
{

     int choiceOfUser=0;
do
    {
        system("cls");
    cout<<"DODAWANIE TRANSAKCJI:"<<endl;
        cin.clear();
        cin.ignore();
        cout<<"czy transakcja dotyczy dnia dzisiejszego?"<<endl;
    cout<<"1. TAK"<<endl;
    cout<<"2. NIE"<<endl;
    cin>>choiceOfUser;
    } while (choiceOfUser!=1 && choiceOfUser!=2);


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

    return (lastTransactionId);
}

void AccountManager::addIncome()
{
    system("cls");
    cout<<"DODAJ PRZYCHOD"<<endl;
    lastIncomeId=addTransaction(lastIncomeId);
    incomes.push_back(transaction);
    fileWithIncomes.saveLastTransactionToFile(transaction, idOfLoggedUser, "Incomes.xml");
}

void AccountManager::addExpense()
{
    system("cls");
    cout<<"DODAJ WYDATEK"<<endl;
    lastExpenseId=addTransaction(lastExpenseId);
    expenses.push_back(transaction);
    fileWithExpenses.saveLastTransactionToFile(transaction, idOfLoggedUser, "Expenses.xml");
}

int AccountManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
}

Date AccountManager::divideDateToDayMonthYear(int dateToConvert)
{
    string date = additionalMethods.convertIntToString(dateToConvert);

    Date sDate;
    sDate.setYear(atoi((date.substr(0,4)).c_str()));
    sDate.setMonth(atoi((date.substr(4,2)).c_str()));
    sDate.setDay(atoi((date.substr(6,2)).c_str()));
    return sDate;
}

vector <Transaction> AccountManager::getTransactionsFromSpecificPeriod(string beginningDateToSum, string endingDateToSum, vector <Transaction> transactions)
{
    int dateFromTransaction;
    int convertedBeginningDateToSum=additionalMethods.convertDateFromStringToIntWithoutPauses(beginningDateToSum);
    int convertedEndingDateToSum=additionalMethods.convertDateFromStringToIntWithoutPauses(endingDateToSum);

    transactionsInBalance.clear();

    for (int i=0; i<transactions.size(); i++)
    {
        dateFromTransaction=transactions[i].getDateOfTransaction();


            if (dateFromTransaction>=convertedBeginningDateToSum &&
                dateFromTransaction<=convertedEndingDateToSum)
                transactionsInBalance.push_back(transactions[i]);
    }
    return transactionsInBalance;
}


void AccountManager::printAllTransactionsToBalance(string typeOfTransactions, vector <Transaction> transactions)
{
    float sumOfAllTransactions;
    cout<<typeOfTransactions<<endl;
     if (transactions.size()==0)
        cout<<"BRAK WPISOW W TYM PRZEDZIALE"<<endl;
     else{
          cout<<"DATA / OPIS / KWOTA"<<endl;
    for(int i=0; i<transactions.size(); i++)
    {
        cout.precision(2);
        cout<<fixed;
          cout<<additionalMethods.convertDateFromIntToStringAndAddPauses(transactions[i].getDateOfTransaction())<<" / "
          <<transactions[i].getTransactionDescription()<<" / "
          <<transactions[i].getAmountOfMoneyInTransaction()<<endl;
          sumOfAllTransactions=sumOfAllTransactions+transactions[i].getAmountOfMoneyInTransaction();
    }
    cout<<"SUMA: "<<sumOfAllTransactions<<endl;
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

vector <Transaction> AccountManager::getTransactionsOfThisMonth(vector <Transaction> transactions)
{
    int date;
    string dateToString;
    int month;
    transactionsInBalance.clear();

    for(int i=0; i<transactions.size(); i++)
    {
        date=transactions[i].getDateOfTransaction();
        dateToString=additionalMethods.convertIntToString(date);
        dateToString = dateToString.erase(0,4);
        dateToString = dateToString.erase(2,2);
        month = atoi(dateToString.c_str());

        if (month==getAcctualMonthFromSystem())
        transactionsInBalance.push_back(transactions[i]);
    }
    return transactionsInBalance;
}

void AccountManager::balanceOfSpecificPeriod(string date1, string date2)
{
    system("cls");
    incomesInBalance=getTransactionsFromSpecificPeriod(date1, date2, incomes);
    sort(incomesInBalance.begin(), incomesInBalance.end());
    printAllTransactionsToBalance("PRZYCHODY", incomesInBalance);
    cout<<endl;
    expensesInBalance=getTransactionsFromSpecificPeriod(date1, date2, expenses);
    sort(expensesInBalance.begin(), expensesInBalance.end());
    printAllTransactionsToBalance("WYDATKI", expensesInBalance);
    cout<<endl;
    cout<<"BILANS:"<<endl<<sumUpIncomesAndExpensesToBalance()<<endl;
    system ("pause");
}

string AccountManager::chooseDate( string textToView)
{
    while(1)
    {
    system("cls");
    string date;
 cout<<textToView<<endl;
 cin>>date;

 if(ifDateIsCorrect(date)==1)
 return date;

 cout<<"zle wprowadzona data, sprobuj ponownie"<<endl;
 system("pause");
 }
}

void AccountManager::balance()
{
    int choiceOfUser;

    do
    {
        cin.clear();
        cin.ignore();
    balanceMenu();
    cin>>choiceOfUser;
    } while (choiceOfUser!=1 && choiceOfUser!=2 && choiceOfUser!=3);


    switch (choiceOfUser)
    {
    case 1:

        balanceOfThisMonth();
        break;
    case 2:

        balanceOfPreviousMonth();
        break;
    case 3:
        string date1=chooseDate("podaj date (w formacie rrrr-mm-dd), od ktorej zaczniemy liczyc bilans");
        string date2=chooseDate("podaj date (w formacie rrrr-mm-dd), na ktorej skonczymy liczyc bilans");

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

void AccountManager::getLastTransactionsId()
{
    lastExpenseId=fileWithExpenses.findHighestTransactionId();
    lastIncomeId=fileWithIncomes.findHighestTransactionId();
}

vector <Transaction> AccountManager::getTransactionsOfPrevMonth(vector <Transaction> transactions)
{
    string date;
    int dateBeforeConversion;
    string dateAsString;
    int month, year;
    transactionsInBalance.clear();
    for(int i=0; i<transactions.size(); i++)
    {
        dateBeforeConversion=transactions[i].getDateOfTransaction();
        date=additionalMethods.convertIntToString(dateBeforeConversion);
        date = date.erase(0,4);
        date = date.erase(2,2);
        month = atoi(date.c_str());

        dateBeforeConversion=transactions[i].getDateOfTransaction();
        date=additionalMethods.convertIntToString(dateBeforeConversion);
        date = date.erase(4,4);
        year = atoi(date.c_str());
        if((getAcctualMonthFromSystem()!=1) && getAcctualYearFromSystem()==year)
           {
            if(month==(getAcctualMonthFromSystem()-1))
            transactionsInBalance.push_back(transactions[i]);
            }
        else
        {
            if((getAcctualMonthFromSystem()==1) && (month==12) && (getAcctualYearFromSystem()-1==year))
            transactionsInBalance.push_back(transactions[i]);
        }
    }

    return transactionsInBalance;
}

void AccountManager::balanceOfSpecificMonth2ndPart()
{
    printAllTransactionsToBalance("PRZYCHODY", incomesInBalance);
    cout<<endl;
    printAllTransactionsToBalance("WYDATKI", expensesInBalance);
    cout<<endl;
    cout<<"BILANS:"<<endl<<sumUpIncomesAndExpensesToBalance()<<endl;
    system ("pause");
}

void AccountManager::balanceOfPreviousMonth()
{
    system("cls");
    incomesInBalance=getTransactionsOfPrevMonth(incomes);
    sort(incomesInBalance.begin(), incomesInBalance.end());
    expensesInBalance=getTransactionsOfPrevMonth(expenses);
    sort(expensesInBalance.begin(), expensesInBalance.end());
    balanceOfSpecificMonth2ndPart();
}

void AccountManager::balanceOfThisMonth()
{
    system("cls");
    incomesInBalance=getTransactionsOfThisMonth(incomes);
    sort(incomesInBalance.begin(), incomesInBalance.end());
    expensesInBalance=getTransactionsOfThisMonth(expenses);
    sort(expensesInBalance.begin(), expensesInBalance.end());
    balanceOfSpecificMonth2ndPart();
}
