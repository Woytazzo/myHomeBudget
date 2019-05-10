#include "FileWithIncomes.h"

void FileWithIncomes::saveIncomesToFile(vector <Transaction> incomes, int idOfLoggedUser)
{
    CMarkup xmlTemp;
    int i=0;

if(xmlTemp.Load("E:\\PrzyszlyProgramista\\myHomeBudget\\Incomes.xml")==0)
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("INCOMES");
}

else
xml.FindElem();
xml.IntoElem();
    while(i<incomes.size())
    {
xml.AddElem("INCOME");
xml.IntoElem();
xml.AddElem( "USER_ID", idOfLoggedUser);
xml.AddElem( "TRANSACTION_ID", incomes[i].getTransactionId()); //
xml.AddElem( "DATE", incomes[i].getDateOfTransaction());
xml.AddElem( "INFO", incomes[i].getTransactionDescription());
xml.AddElem( "AMOUNT", additionalMethods.convertFloatToString(incomes[i].getAmountOfMoneyInTransaction() ));
xml.OutOfElem();
i++;
   }
xml.Save( "E:\\PrzyszlyProgramista\\myHomeBudget\\Incomes.xml");
xml.ResetPos();
}

vector <Transaction> FileWithIncomes::loadIncomesFromFile(int idOfLoggedUser)
{
    vector <Transaction> incomes;

    xml.Load( "E:\\PrzyszlyProgramista\\myHomeBudget\\Incomes.xml" );
    incomes = convertIncomesDataFromXmlToVector(idOfLoggedUser);
    return incomes;
}

vector <Transaction> FileWithIncomes::convertIncomesDataFromXmlToVector(int idOfLoggedUser)
{
int idOfUser;
Transaction income;
vector <Transaction> incomes;
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
    income.setTransactionId(atoi( MCD_2PCSZ(xml.GetData()) ));
    xml.FindElem( "DATE" );
    income.setDateOfTransaction(xml.GetData());
    xml.FindElem( "INFO" );
    income.setTransactionDescription(xml.GetData());
    xml.FindElem( "AMOUNT" );
    income.setAmountOfMoneyInTransaction(atof(xml.GetData().c_str()));
    xml.OutOfElem();
    incomes.push_back(income);
    }
    else xml.OutOfElem();
}
return incomes;
}




void FileWithIncomes::saveLastIncomeToFile(Transaction income, int idOfLoggedUser)
{

if(xml.Load("E:\\PrzyszlyProgramista\\myHomeBudget\\Incomes.xml")==0)
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("INCOMES");
}
else
{
    xml.ResetPos();
    xml.FindElem();
}

xml.IntoElem();
xml.AddElem("INCOME");
xml.IntoElem();
xml.AddElem( "USER_ID", idOfLoggedUser);
xml.AddElem( "TRANSACTION_ID", income.getTransactionId()); //
xml.AddElem( "DATE", income.getDateOfTransaction());
xml.AddElem( "INFO", income.getTransactionDescription());
xml.AddElem( "AMOUNT", additionalMethods.convertFloatToString(income.getAmountOfMoneyInTransaction() ));
xml.OutOfElem();
xml.OutOfElem();

xml.Save( "E:\\PrzyszlyProgramista\\myHomeBudget\\Incomes.xml");
xml.ResetPos();
}
