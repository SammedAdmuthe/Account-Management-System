// Authors: Sammed Sunil Admuthe
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "AccountManager.h"

// IMPLEMENTATION OF SINGLETON PATTERN

AccountManager* AccountManager::instance = nullptr;

AccountManager::AccountManager(double initialBalance) {

    if(isNewAccount())
    {
        balance = initialBalance;
    }
}

bool AccountManager::isNewAccount() {
    std::string filename = "accountLog.txt";
    std::ifstream file(filename);
    std::string line;

    if (!file) {
        // std::cerr << "Unable to open file: " << filename << std::endl;
        return true;
    }
    std::string symbol;
    double totalPortfolioValue;
    double bal = -1;
    std::string getTime;
    while (getline(file, line)) {
        std::istringstream iss(line);

        if (iss >> totalPortfolioValue >> bal >> getTime) {
            balance = bal;
        }
    }

    balance = bal;
    file.close();
    // std::cout<<"AccountManager Balance is : "<<balance<<std::endl;
    return balance == -1;
}
AccountManager* AccountManager::getInstance(double initialBalance){
    if(instance == nullptr){
        instance = new AccountManager(initialBalance);
    }
    return instance;
}
double AccountManager::getBalance() const{
    return balance;
}
void AccountManager::setBalance(double amount){
    balance = amount;
}