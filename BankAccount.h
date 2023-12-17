//Author:  Sammed Sunil Admuthe

// BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Account.h"
#include <string>
class BankAccount : public Account {


public:
    // BankAccount();
    BankAccount(double initialBalance);
    void deposit(double amount);
    void withdraw(double amount);
    void accountBalance();
    void recordBankTransaction(std::string event, double amount);
    void viewBankTransactionHistory();
    ~BankAccount() {}
};

#endif // BANKACCOUNT_H
