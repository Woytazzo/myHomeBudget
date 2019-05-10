#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "AccountManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    AccountManager *accountManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPANSES;

    public:
PersonalBudget(string nameOfFileWithIncomes, string nameOfFileWithExpanses, string nameOfFileWithUsers)
: userManager(nameOfFileWithUsers) , NAME_OF_FILE_WITH_EXPANSES(nameOfFileWithExpanses), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes)
{

};

~PersonalBudget()
{
    delete accountManager;
    //void mainMenu();
};

void registration();
void logIn();
void addIncome();
void addExpanse();
void showBalanceOfThisMonth();
void showBalanceOfPrevMonth();
void showBalanceOfChosenPeriod();
void changePassword();
void logOut();
void mainMenuAfterLaunch();
void mainMenuAfterLogIn();
void mainMenus();
void BalanceMenu();
void balance();

};

#endif
