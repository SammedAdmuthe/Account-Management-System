//Author:  Sammed Sunil Admuthe

// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
// private:
//     static double balance;
public:
    // Account();
    // double getBalance() const;
    // void setBalance(double amount);
    virtual double getBalance() const = 0;
    virtual void setBalance(double amount) = 0;
    virtual ~Account();
};

#endif // ACCOUNT_H
