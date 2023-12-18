#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include "Account.h"
class AccountFactory {
public:
    virtual Account* createAccount(double initialBalance) const = 0;
    virtual ~AccountFactory() {}
};

#endif