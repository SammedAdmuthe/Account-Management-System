#ifndef BANK_ACCOUNT_FACTORY_H
#define BANK_ACCOUNT_FACTORY_H

#include "BankAccount.h"

class BankAccountFactory : public AccountFactory {
public:
    Account* createAccount(double initialBalance) const override {
        return new BankAccount(initialBalance);
    }
};

#endif
