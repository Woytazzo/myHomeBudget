#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <iostream>
#include <algorithm>
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
    vector <Transaction> transactionsInBalance;

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
    int getTodaysDateFromSystem();
    int setDateManuallyByUser();
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
    getLastTransactionId();
    };
    void showMenu();
    void showBalanceInnerMenu();
    void addTransaction();
    void addIncome();
    void addExpense();
    void balanceOfSpecificPeriod(string date1, string date2);
    void getLastTransactionId();

    Date divideDateToDayMonthYear(int dateToConvert);
    void printAllTransactionsToBalance(string typeOfTransactions, vector <Transaction> transactions);
    vector <Transaction> getTransactionsFromSpecificPeriod(string beginningDateToSum, string endingDateToSum, vector <Transaction> transactions);
    float sumUpIncomesAndExpensesToBalance();
    vector <Transaction> getTransactionsOfThisMonth(vector <Transaction> transactions);
    void balanceOfThisMonth();
    string chooseDate( string textToView);
    void balance();
    void balanceMenu();
    void balanceOfPreviousMonth();
    vector <Transaction> getTransactionsOfPrevMonth(vector <Transaction> transactions);
    void balanceOfSpecificMonth2ndPart();
    bool sortByDate(Transaction &A, Transaction &B);
};

#endif // ACCOUNTMANAGER_H
