#include "PersonalBudget.h"
void PersonalBudget::registration()
{
    userManager.registration();
}
void PersonalBudget::logIn()
{
    userManager.logIn();
    if(userManager.ifUserIsLoggedIn())
    {
       accountManager = new AccountManager(NAME_OF_FILE_WITH_ExpenseS, NAME_OF_FILE_WITH_INCOMES, userManager.getIdOfLoggedUser());
    }
}
void PersonalBudget::addIncome()
{
if(userManager.ifUserIsLoggedIn())
        accountManager->addIncome();
    else{
        cout<<"Zaloguj sie na swoje konto"<<endl;
        system("pause");
    }
}
void PersonalBudget::addExpense()
{
    if(userManager.ifUserIsLoggedIn())
        accountManager->addExpense();
    else{
        cout<<"Zaloguj sie na swoje konto"<<endl;
        system("pause");
    }
}
void PersonalBudget::balance()
{
        if(userManager.ifUserIsLoggedIn())
        accountManager->balance();
    else{
        cout<<"Zaloguj sie na swoje konto"<<endl;
        system("pause");
    }
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}
void PersonalBudget::logOut()
{
    userManager.logOut();
    delete accountManager;
    accountManager = NULL;
}

void PersonalBudget::mainMenuAfterLaunch()
{
    system ("cls");
    cout<<"Witaj w programie DOMOWY BUDZET!"<<endl<<endl;
    cout<<"Wybierz i zatwierdz (ENTER) jedna z opcji:"<<endl<<endl;
    cout<<"1. REJESTRACJA"<<endl<<"2. LOGOWANIE"<<endl<<"3. WYJSCIE Z PROGRAMU"<<endl;
    char choice;
    cin>>choice;
        switch (choice)
        {
        case '1':
            registration();
            break;
        case '2':
            logIn();
            break;
        case '3':
            exit(0);
            break;
        }
}

void PersonalBudget::mainMenuAfterLogIn()
{
    system ("cls");
    cout<<"Witaj"<<endl;
cout<<"Wybierz i zatwierdz (ENTER) jedna z opcji:"<<endl<<endl;
    cout<<"1. DODAJ PRZYCHOD"<<endl<<"2. DODAJ WYDATEK"<<endl<<"3. OBLICZ BILANS WYBRANEGO OKRESU"<<endl<<"4. ZMIANA HASLA"<<endl<<"5. WYLOGUJ"<<endl;
    char choice;
    cin>>choice;
        switch (choice)
        {
        case '1':
            addIncome();
            break;
        case '2':
            addExpense();
            break;
        case '3':
            balance();
            break;
        case '4':
            changePassword();
            break;
        case '5':
            logOut();
            break;
        }
}

void PersonalBudget::mainMenus()
{


    while(true)
    {
        if (userManager.ifUserIsLoggedIn())
            mainMenuAfterLogIn();
        else
            mainMenuAfterLaunch();
    }
}
