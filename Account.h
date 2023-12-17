//Author:  Sammed Sunil Admuthe

// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    static double balance;
public:
    Account();
    double getBalance() const;
    void setBalance(double amount);
    virtual ~Account();
};

#endif // ACCOUNT_H
