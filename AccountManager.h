#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "User.h"
#include "Date.h"
#include "Transaction.h"
#include "AdditionalMethods.h"
#include "FileWithIncomes.h"
#include "FileWithExpanses.h"

using namespace std;

class AccountManager
{

    Date date;
    User user;
    Transaction transaction;

    vector <Transaction> expanses;
    vector <Transaction> incomes;
    vector <Transaction> expansesInBalance;
    vector <Transaction> incomesInBalance;

    Date dateWithSeparationForYearMonthDay;
    FileWithExpanses fileWithExpanses;
    FileWithIncomes fileWithIncomes;
    AdditionalMethods additionalMethods;
    string dateByUser;
    int idOfLoggedUser;
    int lastTransactionId;

    string addZeroIfTheresOnlyOneNumber(string number);

    int getAcctualYearFromSystem();
    int getAcctualMonthFromSystem();
    int getAcctualDayFromSystem();
    string getTodaysDateFromSystem();
    string setDateManuallyByUser();
    bool ifDateIsCorrect(string date);
    void getYearMonthDayFromWholeDate(string dateByUser);
    int giveAmountOfDaysInMonth(Date date);

    string getInfoAboutTransaction();
    float getAmountOfMoney();
    int getIdOfLoggedUser();



public:
    AccountManager(string NAMEOFFILEWITHEXPANSES, string NAMEOFFILEWITHINCOMES, int IDOFLOGGEDUSER): fileWithExpanses(NAMEOFFILEWITHEXPANSES), fileWithIncomes(NAMEOFFILEWITHINCOMES)
    {
    idOfLoggedUser = IDOFLOGGEDUSER;
    incomes = fileWithIncomes.loadIncomesFromFile(idOfLoggedUser);
    expanses = fileWithExpanses.loadExpansesFromFile(idOfLoggedUser);
    lastTransactionId = getLastTransactionId();
    };
    void showMenu();
    void showBalanceInnerMenu();
    void addTransaction();
    void addIncome();
    void addExpanse();
    void balanceOfSpecificPeriod(Date date1, Date date2);
    int getLastTransactionId();
    void getIncomesFromSpecificPeriod(Date beginningDateToSum, Date endingDateToSum);
    struct Date divideDateToDayMonthYear(string date);
    void printAllIncomesToBalance();
    void getExpansesFromSpecificPeriod(Date beginningDateToSum, Date endingDateToSum);
    void printAllExpansesToBalance();
    float sumUpIncomesAndExpansesToBalance();
    void getIncomesOfThisMonth();
    void getExpansesOfThisMonth();
    void balanceOfThisMonth();
    Date chooseOpeningDate();
    Date chooseClosingDate();
    void balance();
    void balanceMenu();
    void balanceOfPreviousMonth();
    void getExpansesOfPrevMonth();
    void getIncomesOfPrevMonth();
    int makePartitionOfIncomes(int p, int r);
    void quicksort(int p, int r);
    void sortingIncomesByDate();

};

#endif // ACCOUNTMANAGER_H
