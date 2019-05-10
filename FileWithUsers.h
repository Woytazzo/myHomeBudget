#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    const string NAME_OF_FILE_WITH_USERS;
    CMarkup xml;
public:
    FileWithUsers(string FILEWITHUSERS) : NAME_OF_FILE_WITH_USERS(FILEWITHUSERS){};
    void saveAllUsersToFile(vector <User> users);
    vector <User> loadUsersFromFile();
    void ifFileOpens(CMarkup xml);
    CMarkup loadDataToXmlFromFile();
    vector <User> convertUsersDataFromXmlToVector();
    void addUserToFile(User user);
};
#endif
