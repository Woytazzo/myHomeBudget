#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <algorithm>

using namespace std;

class Transaction
{
    int transactionId;
    int dateOfTransaction;
    string transactionDescription;
    float amountOfMoneyInTransaction;


public:
    bool operator <(Transaction obj) const{
        return (dateOfTransaction < obj.dateOfTransaction);
}
    void setTransactionId(int transactionId);
    void setDateOfTransaction(int dateOfTransaction);
    void setTransactionDescription(string transactionDescription);
    void setAmountOfMoneyInTransaction(float amountOfMoneyInTransaction);

    int getTransactionId();
    int getDateOfTransaction();
    string getTransactionDescription();
    float getAmountOfMoneyInTransaction();

};

#endif
