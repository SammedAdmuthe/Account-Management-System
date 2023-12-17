//Author:  Sammed Sunil Admuthe

// StockAccount.h
#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H

#include <string>
#include "Account.h"
#include "DoublyLinkedList.h"

class StockAccount : public Account {

private:
    DoublyLinkedList stockData;
    struct StockData {
        std::string symbol;
        double price;

        StockData():symbol(""), price(0){}
    };
    
public:
    StockAccount(double initialBalance);
    void setBalance(double amount);
    double getBalance() const;
    DoublyLinkedList& getStockPortfolioInfo(const std::string& filename);
    static StockData readStockData (std::string filename, std::string symbol);
    static double displayPriceOfStock(std::string symbol);
    void displayCurrentPortfolio() const;
    void buyShares(const std::string& symbol, int shares, double maxPrice);
    void sellShares(const std::string& symbol, int shares, double minPrice);
    void recordTransaction(const std::string& type, const std::string& symbol, int shares, double price);
    void recordWithdrawal(double totalCost);
    void recordDeposit(double totalCost);    
    void viewTransactionHistory();
    ~StockAccount();
};

#endif // STOCKACCOUNT_H
