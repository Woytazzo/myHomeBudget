#include "Transaction.h"

void Transaction::setTransactionId(int transactionId)
{
    if(transactionId>=0)
    this->transactionId=transactionId;
}
void Transaction::setDateOfTransaction(string dateOfTransaction)
{
    this->dateOfTransaction=dateOfTransaction;
}
void Transaction::setTransactionDescription(string transactionDescription)
{
    this->transactionDescription=transactionDescription;
}

void Transaction::setAmountOfMoneyInTransaction(float amountOfMoneyInTransaction)
{
    this->amountOfMoneyInTransaction=amountOfMoneyInTransaction;
}

    int Transaction::getTransactionId()
    {
        return transactionId;
    }
    string Transaction::getDateOfTransaction()
    {
        return dateOfTransaction;
    }
    string Transaction::getTransactionDescription()
    {
        return transactionDescription;
    }
    float Transaction::getAmountOfMoneyInTransaction()
    {
        return amountOfMoneyInTransaction;
    }



