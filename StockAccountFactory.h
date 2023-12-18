#ifndef STOCKACCOUNTFACTORY_H
#define STOCKACCOUNTFACTORY_H

#include "AccountFactory.h"
#include "StockAccount.h"
#include "ListNode.h"


class StockAccountFactory : public AccountFactory {
public:
    Account* createAccount(double initialBalance) const override {
        return new StockAccount(initialBalance);
    }
};

#endif