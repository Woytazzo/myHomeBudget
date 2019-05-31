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
#include "FileWithExpenses.h"

using namespace std;

class AccountManager
{

    Date date;
    User user;
    Transaction transaction;

    vector <Transaction> expenses;
    vector <Transaction> incomes;
    vector <Transaction> expensesInBalance;
    vector <Transaction> incomesInBalance;

    Date dateWithSeparationForYearMonthDay;
    FileWithExpenses fileWithExpenses;
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
    AccountManager(string NAMEOFFILEWITHEXPENSES, string NAMEOFFILEWITHINCOMES, int IDOFLOGGEDUSER): fileWithExpenses(NAMEOFFILEWITHEXPENSES), fileWithIncomes(NAMEOFFILEWITHINCOMES)
    {
    idOfLoggedUser = IDOFLOGGEDUSER;
    incomes = fileWithIncomes.loadTransactionsFromFile(idOfLoggedUser, "Incomes.xml");
    expenses = fileWithExpenses.loadTransactionsFromFile(idOfLoggedUser, "Expenses.xml");
    lastTransactionId = getLastTransactionId();
    };
    void showMenu();
    void showBalanceInnerMenu();
    void addTransaction();
    void addIncome();
    void addExpense();
    void balanceOfSpecificPeriod(Date date1, Date date2);
    int getLastTransactionId();
    void getIncomesFromSpecificPeriod(Date beginningDateToSum, Date endingDateToSum);
    struct Date divideDateToDayMonthYear(string date);
    void printAllIncomesToBalance();
    void getExpensesFromSpecificPeriod(Date beginningDateToSum, Date endingDateToSum);
    void printAllExpensesToBalance();
    float sumUpIncomesAndExpensesToBalance();
    void getIncomesOfThisMonth();
    void getExpensesOfThisMonth();
    void balanceOfThisMonth();
    Date chooseOpeningDate();
    Date chooseClosingDate();
    void balance();
    void balanceMenu();
    void balanceOfPreviousMonth();
    void getExpensesOfPrevMonth();
    void getIncomesOfPrevMonth();
    int makePartitionOfIncomes(int p, int r);
    void quicksort(int p, int r);
    void sortingIncomesByDate();

};

#endif // ACCOUNTMANAGER_H
