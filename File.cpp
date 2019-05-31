#include "FileWithIncomes.h"

void File::saveTransactionsToFile(vector <Transaction> transactions, int idOfLoggedUser, string fileName)
{
    CMarkup xmlTemp;
    int i=0;

if(xmlTemp.Load(fileName)==0)
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("TRANSACTIONS");
}

else
xml.FindElem();
xml.IntoElem();
    while(i<transactions.size())
    {
xml.AddElem("TRANSACTION");
xml.IntoElem();
xml.AddElem( "USER_ID", idOfLoggedUser);
xml.AddElem( "TRANSACTION_ID", transactions[i].getTransactionId()); //
xml.AddElem( "DATE", transactions[i].getDateOfTransaction());
xml.AddElem( "INFO", transactions[i].getTransactionDescription());
xml.AddElem( "AMOUNT", additionalMethods.convertFloatToString(transactions[i].getAmountOfMoneyInTransaction() ));
xml.OutOfElem();
i++;
   }
xml.Save(fileName);
xml.ResetPos();
}

vector <Transaction> File::loadTransactionsFromFile(int idOfLoggedUser, string fileName)
{
    vector <Transaction> transactions;

    xml.Load( fileName );
    transactions = convertTransactionsDataFromXmlToVector(idOfLoggedUser);
    return transactions;
}

vector <Transaction> File::convertTransactionsDataFromXmlToVector(int idOfLoggedUser)
{
int idOfUser;
Transaction transaction;
vector <Transaction> transactions;
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
    transaction.setTransactionId(atoi( MCD_2PCSZ(xml.GetData()) ));
    xml.FindElem( "DATE" );
    transaction.setDateOfTransaction(xml.GetData());
    xml.FindElem( "INFO" );
    transaction.setTransactionDescription(xml.GetData());
    xml.FindElem( "AMOUNT" );
    transaction.setAmountOfMoneyInTransaction(atof(xml.GetData().c_str()));
    xml.OutOfElem();
    transactions.push_back(transaction);
    }
    else xml.OutOfElem();
}
return transactions;
}


void File::saveLastTransactionToFile(Transaction transaction, int idOfLoggedUser, string fileName)
{

if(xml.Load(fileName)==0)
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("TRANSACTIONS");
}
else
{
    xml.ResetPos();
    xml.FindElem();
}
xml.IntoElem();
xml.AddElem("TRANSACTION");
xml.IntoElem();
xml.AddElem( "USER_ID", idOfLoggedUser);
xml.AddElem( "TRANSACTION_ID", transaction.getTransactionId()); //
xml.AddElem( "DATE", transaction.getDateOfTransaction());
xml.AddElem( "INFO", transaction.getTransactionDescription());
xml.AddElem( "AMOUNT", additionalMethods.convertFloatToString(transaction.getAmountOfMoneyInTransaction() ));
xml.OutOfElem();
xml.OutOfElem();

xml.Save( fileName);
xml.ResetPos();
}
