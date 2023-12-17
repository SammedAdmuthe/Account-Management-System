//Author:  Sammed Sunil Admuthe

#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

double Account::balance = 0;


Account::Account()
{
    std::string filename = "accountLog.txt";
    std::ifstream file(filename);
    std::string line;

    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    std::string symbol;
    double totalPortfolioValue;
    double bal = -1;
    std::string getTime;
    while (getline(file, line)) {
        std::istringstream iss(line);

        if (iss >> totalPortfolioValue >> bal >> getTime) {
            Account::balance = bal;
        }
    }

    Account::balance = bal;
    file.close();
}

double Account::getBalance() const
{ 
    return Account::balance; 
}
void Account::setBalance(double amount)
{ 
    Account::balance = amount;

}

Account::~Account(){
    
}