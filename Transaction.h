#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
    int transactionId;
    string dateOfTransaction;
    string transactionDescription;
    float amountOfMoneyInTransaction;


public:
    void setTransactionId(int transactionId);
    void setDateOfTransaction(string dateOfTransaction);
    void setTransactionDescription(string transactionDescription);
    void setAmountOfMoneyInTransaction(float amountOfMoneyInTransaction);

    int getTransactionId();
    string getDateOfTransaction();
    string getTransactionDescription();
    float getAmountOfMoneyInTransaction();

};

#endif
