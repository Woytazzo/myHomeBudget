#include "FileWithIncomes.h"

vector <Transaction> File::loadTransactionsFromFile(int idOfLoggedUser, string fileName)
{
    vector <Transaction> transactions;

    xml.Load( fileName );
    transactions = convertTransactionsDataFromXmlToVector(idOfLoggedUser);
    return transactions;
}

int File::findHighestTransactionId(int highestTransactionId)
{
    int transactionIdToCheck=0;

    xml.ResetPos();
xml.FindElem();
xml.IntoElem();

while ( xml.FindElem() )
{
    xml.IntoElem();
    xml.FindElem( "USER_ID" );
    xml.FindElem( "TRANSACTION_ID" );
    transactionIdToCheck = atoi( MCD_2PCSZ(xml.GetData()) );
    if(transactionIdToCheck>highestTransactionId)
        highestTransactionId=transactionIdToCheck;
    else xml.OutOfElem();
}
return highestTransactionId;
}

vector <Transaction> File::convertTransactionsDataFromXmlToVector(int idOfLoggedUser)
{
int idOfUser;
int dateConvertedToIntFromXml;
string dateToConvert;
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
    dateToConvert=xml.GetData();
    dateToConvert.erase(7,1);
    dateToConvert.erase(4,1);
    dateConvertedToIntFromXml=atoi((dateToConvert).c_str());
    //TUTAJ DODAJEMY
    transaction.setDateOfTransaction(dateConvertedToIntFromXml);

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
string date=additionalMethods.convertDateFromIntToStringAndAddPauses(transaction.getDateOfTransaction());

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
xml.AddElem( "DATE", date);
xml.AddElem( "INFO", transaction.getTransactionDescription());
xml.AddElem( "AMOUNT", additionalMethods.convertFloatToString(transaction.getAmountOfMoneyInTransaction() ));
xml.OutOfElem();
xml.OutOfElem();

xml.Save( fileName);
xml.ResetPos();
}
