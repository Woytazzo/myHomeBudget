#include "FileWithExpanses.h"

void FileWithExpanses::saveExpansesToFile(vector <Transaction> expanses, int idOfLoggedUser)
{
    CMarkup xmlTemp;
    int i=0;

xml.SetDoc( "E:\\PrzyszlyProgramista\\myHomeBudget\\Incomes.xml" );
if(xmlTemp.Load("E:\\PrzyszlyProgramista\\myHomeBudget\\Expanses.xml")==0)
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("EXPANSES");
}

else
xml.FindElem();
xml.IntoElem();
    while(i<expanses.size())
    {
xml.AddElem("EXPANSE");
xml.IntoElem();
xml.AddElem( "USER_ID", idOfLoggedUser);
xml.AddElem( "TRANSACTION_ID", expanses[i].getTransactionId()); //
xml.AddElem( "DATE", expanses[i].getDateOfTransaction());
xml.AddElem( "INFO", expanses[i].getTransactionDescription());
xml.AddElem( "AMOUNT", additionalMethods.convertFloatToString(expanses[i].getAmountOfMoneyInTransaction() ));
xml.OutOfElem();
i++;
   }
xml.Save( "E:\\PrzyszlyProgramista\\myHomeBudget\\Expanses.xml");
xml.ResetPos();
}

vector <Transaction> FileWithExpanses::loadExpansesFromFile(int idOfLoggedUser)
{
    vector <Transaction> expanses;
    xml.Load( "E:\\PrzyszlyProgramista\\myHomeBudget\\Expanses.xml" );
    expanses = convertExpansesDataFromXmlToVector(idOfLoggedUser);
    return expanses;
}

vector <Transaction> FileWithExpanses::convertExpansesDataFromXmlToVector(int idOfLoggedUser)
{
int idOfUser;
Transaction expanse;
vector <Transaction> expanses;
xml.ResetPos();
xml.FindElem();
xml.IntoElem();

while ( xml.FindElem() )
{
    xml.IntoElem();
    xml.FindElem( "USER_ID" );
    idOfUser=atoi( MCD_2PCSZ(xml.GetData()) );
    if(idOfUser==idOfLoggedUser)
    {
    xml.FindElem( "TRANSACTION_ID" );
    expanse.setTransactionId(atoi( MCD_2PCSZ(xml.GetData()) ));
    xml.FindElem( "DATE" );
    expanse.setDateOfTransaction(xml.GetData());
    xml.FindElem( "INFO" );
    expanse.setTransactionDescription(xml.GetData());
    xml.FindElem( "AMOUNT" );
    expanse.setAmountOfMoneyInTransaction(atof(xml.GetData().c_str()));
    xml.OutOfElem();
    expanses.push_back(expanse);
    }
    else xml.OutOfElem();
}
return expanses;
}

void FileWithExpanses::saveLastExpanseToFile(Transaction expanse, int idOfLoggedUser)
{

if(xml.Load("E:\\PrzyszlyProgramista\\myHomeBudget\\Expanses.xml")==0)
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("EXPANSES");
}
else
{
    xml.ResetPos();
    xml.FindElem();
}

xml.IntoElem();
xml.AddElem("EXPANSE");
xml.IntoElem();
xml.AddElem( "USER_ID", idOfLoggedUser);
xml.AddElem( "TRANSACTION_ID", expanse.getTransactionId()); //
xml.AddElem( "DATE", expanse.getDateOfTransaction());
xml.AddElem( "INFO", expanse.getTransactionDescription());
xml.AddElem( "AMOUNT", additionalMethods.convertFloatToString(expanse.getAmountOfMoneyInTransaction() ));
xml.OutOfElem();
xml.OutOfElem();

xml.Save( "E:\\PrzyszlyProgramista\\myHomeBudget\\Expanses.xml");
xml.ResetPos();
}
