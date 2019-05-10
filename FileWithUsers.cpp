#include "FileWithUsers.h"

string convertIntToString(int numberToConvert)
{
    ostringstream ss;
ss << numberToConvert;
string str = ss.str();
return str;
}

void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
int i=0;

    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("USERS");

xml.IntoElem();

    while(i<users.size())
    {
xml.AddElem( "USER");
xml.IntoElem();
xml.AddElem( "ID", users[i].getUserId()); //
xml.AddElem( "LOGIN", users[i].getLogin());
xml.AddElem( "PASSWORD", users[i].getPassword());
xml.AddElem( "NAME", users[i].getName() );
xml.AddElem( "SURNAME", users[i].getSurname() );
xml.OutOfElem();
i++;
   }
xml.Save( "E:\\PrzyszlyProgramista\\myHomeBudget\\Users.xml");
}

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xmlTemp;

if(!xml.Load("E:\\PrzyszlyProgramista\\myHomeBudget\\Users.xml"))
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("USERS");
    xml.IntoElem();
}

else
{
xml.FindElem("USERS");
xml.IntoElem();
}

xml.AddElem( "USER");
xml.IntoElem();
xml.AddElem( "ID", user.getUserId());
xml.AddElem( "LOGIN", user.getLogin());
xml.AddElem( "PASSWORD", user.getPassword());
xml.AddElem( "NAME", user.getName() );
xml.AddElem( "SURNAME", user.getSurname() );
xml.OutOfElem();

xml.Save( "E:\\PrzyszlyProgramista\\myHomeBudget\\Users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    vector <User> users;
    xml = loadDataToXmlFromFile();
    users=convertUsersDataFromXmlToVector();
    return users;
}

CMarkup FileWithUsers::loadDataToXmlFromFile()
{
    xml.Load( "E:\\PrzyszlyProgramista\\myHomeBudget\\Users.xml" );
    return xml;
}

vector <User> FileWithUsers::convertUsersDataFromXmlToVector()
{
User user;
vector <User> users;

xml.FindElem(); // root USERS element
xml.IntoElem(); // inside USERS

while ( xml.FindElem("USER") )
{
    xml.IntoElem();
    xml.FindElem( "ID" );
    user.setUserId(atoi( MCD_2PCSZ(xml.GetData()) ));

    xml.FindElem( "LOGIN" );
    user.setLogin(xml.GetData());
    xml.FindElem( "PASSWORD" );
    user.setPassword(xml.GetData());
    xml.FindElem( "NAME" );
    user.setName(xml.GetData());
    xml.FindElem( "SURNAME" );
    user.setSurname(xml.GetData());
    xml.OutOfElem();
    users.push_back(user);
}
return users;
}



