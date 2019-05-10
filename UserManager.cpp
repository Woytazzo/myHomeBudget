#include "UserManager.h"

void UserManager::registration()
{
    system("cls");
    cout<<"REJESTRACJA"<<endl;
    User user = setDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::setDataOfNewUser()
{
    User user;
    user.setUserId(getIdOfNewUser());

    do
    {
        cout << "Podaj login: ";
        cin >> input;
        user.setLogin(input);
    } while (ifLoginExists(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> input;
    user.setPassword(input);

    cout << "Podaj imie: ";
    cin >> input;
    user.setName(input);

    cout << "Podaj nazwisko: ";
    cin >> input;
    user.setSurname(input);


    return user;
}

int UserManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::ifLoginExists(string login)
{
    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
}


void UserManager::logIn()
{
    system("cls");
    cout<<"LOGOWANIE"<<endl;
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int tries = 3; tries > 0; tries--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << tries << ": ";
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    idOfLoggedUser = itr -> getUserId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::logOut()
{
    system("cls");
    idOfLoggedUser = 0;
    cout<<"POMYSLNIE WYLOGOWANO"<<endl;
    system("pause");

}

int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
}
bool UserManager::ifUserIsLoggedIn()
{
    if (idOfLoggedUser>0) return true;
    else return false;
}

void UserManager::changePassword()
{
    system("cls");
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == idOfLoggedUser)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
 fileWithUsers.saveAllUsersToFile(users);
}

