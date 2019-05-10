#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    string input;
    FileWithUsers fileWithUsers;
    int idOfLoggedUser;
    vector <User> users;
    User setDataOfNewUser();
    int getIdOfNewUser();
    bool ifLoginExists(string login);

public:
    UserManager(string nameOfFileWithUsers): fileWithUsers(nameOfFileWithUsers){
    users = fileWithUsers.loadUsersFromFile();
    idOfLoggedUser=0;
    };
    void registration();
    void logIn();
    void logOut();
    int getIdOfLoggedUser();
    bool ifUserIsLoggedIn();
    void changePassword();
};

#endif
