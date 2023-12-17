//Author:  Sammed Sunil Admuthe

#include "StockAccount.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>


#include <iostream>
#include "StockAccount.h" // Add the missing include directive for the StockAccount class

StockAccount::StockAccount(double initialBalance){
    getStockPortfolioInfo("Stock_Portfolio_Info.txt");
    if(getBalance() == -1)
    {
        setBalance(initialBalance);
    }

}
void StockAccount::displayCurrentPortfolio() const{

    std::ifstream file("Stock_Portfolio_Info.txt");
    std::string line;
    std::cout << "Cash balance = $"<<getBalance() << std::endl;

    // Header
    std::cout << std::left 
              << std::setw(15) << "CompanySymbol" 
              << std::setw(10) << "Number" 
              << std::setw(15) << "PricePerShare" 
              << std::setw(15) << "TotalValue" 
              << std::endl;
    double totalValue = 0.0;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string symbol;
        int share;
        if (iss >> symbol >> share) {
            double valuePerShare = StockAccount::displayPriceOfStock(symbol);
            std::cout << std::left 
                << std::setw(15) << symbol
                << std::setw(10) << share
                << std::setw(15) << valuePerShare
                << std::setw(15) << share * valuePerShare
                << std::endl;
            totalValue += share * valuePerShare;
        }
    }
    std::cout<<"Total portfolio value: $"<<totalValue +getBalance()<<std::endl;
    file.close();

}

DoublyLinkedList& StockAccount::getStockPortfolioInfo(const std::string& filename) {

    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string symbol;
        double price;
        if (iss >> symbol >> price) {
            stockData.insert(symbol, price);
        }
    }
    file.close();
    return stockData;
}




StockAccount::StockData StockAccount::readStockData (std::string filename, std::string symbol) {
    std::ifstream file(filename);
    std::string line;
    StockData stockData;

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> result;
        std::string word;

        while (iss >> word) {

            result.push_back(word);
        }
        if(result.size() == 3) {

            if(result[0] == symbol) {
                stockData.symbol = (std::string)result[0];
                stockData.price = std::stod(result[1]);

            }
        }
    }

    file.close();
    
    return stockData;
}

double StockAccount::displayPriceOfStock(std::string symbol) {

    srand(time(NULL));

    // Randomly choose a stock from one of the files
    StockData randomStock = (rand() % 2 == 0) ? readStockData("Result_1.txt", symbol) : readStockData("Result_2.txt", symbol);
    // std::cout<<"Symbol : "<<randomStock.symbol<<" Price: "<<randomStock.price<<std::endl;
    if(randomStock.symbol == "") {
        std::cout<<"Symbol cannot be found"<<std::endl;
    }
    return randomStock.price;
}

void StockAccount::recordTransaction(const std::string& type, const std::string& symbol, int shares, double price) {
    std::ofstream file("stock_transaction_history.txt", std::ios::app); 

    if (!file) {
        std::cerr << "Unable to open the transaction history file." << std::endl;
        return;
    }
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);

    file << type << " " << symbol << " " << shares << " " << price << " " << std::put_time(now_tm, "%H:%M:%S") << std::endl;

    if (!file.good()) {
        std::cerr << "Error occurred while writing to the transaction history file." << std::endl;
    }

    file.close(); // Close the file
}

void StockAccount::buyShares(const std::string& symbol, int shares, double maxPrice) {
    // Check if the stock exists and get its price
    double stockPrice = displayPriceOfStock(symbol);
    if (stockPrice == 0.0) {
        std::cout << "Stock not available." << std::endl;
        return;
    }

    double totalCost = stockPrice * shares;

    // Check if the price is acceptable
    if (stockPrice > maxPrice) {
        std::cout << "Stock price is higher than willing to pay." << std::endl;
        return;
    }

    // Check if enough balance is available
    if (this->getBalance() < totalCost) {
        std::cout << "Insufficient funds." << std::endl;
        return;
    }

    // Process the transaction
    this->setBalance(this->getBalance() - totalCost);
    std::cout<<"See HERE : "<<getBalance()<<std::endl;

    // Add stocks to portfolio (implement addStocksToPortfolio)
    stockData.insert(symbol, shares);

    recordTransaction("Buy", symbol, shares, stockPrice);
    recordWithdrawal(totalCost);
}

void StockAccount::recordWithdrawal(double totalCost) {
    std::ofstream file("bank_transaction_history.txt", std::ios::app); 

    if (!file) {
        std::cerr << "Unable to open the transaction history file." << std::endl;
        return;
    }
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);

    file << "Withdrawal" << " " << totalCost << " " << std::put_time(now_tm,  "%Y-%m-%d,%H:%M:%S") << " " << getBalance() << " " <<"Stock"<< std::endl;

    if (!file.good()) {
        std::cerr << "Error occurred while writing to the transaction history file." << std::endl;
    }

    file.close(); // Close the file
}
void StockAccount::sellShares(const std::string& symbol, int shares, double minPrice) {
    double currentPrice = displayPriceOfStock(symbol);

    // Check if the stock exists and if there are enough shares
    if (stockData.getShares(symbol) < shares) {
        std::cout << "Insufficient shares or stock not in portfolio." << std::endl;
        return;
    }

    if (currentPrice < minPrice) {
        std::cout << "Current stock price is lower than the desired selling price." << std::endl;
        return;
    }

    // Update portfolio and bank balance
    // Assuming methods for updating portfolio and bank balance
    stockData.insert(symbol, -shares);  // Subtract shares
    setBalance(getBalance() + shares * currentPrice);  // Add cash from selling shares

    // Record the transaction
    recordTransaction("Sell", symbol, shares, currentPrice);
    recordDeposit(shares * currentPrice);
}
void StockAccount::recordDeposit(double totalCost) {
    std::ofstream file("bank_transaction_history.txt", std::ios::app); 

    if (!file) {
        std::cerr << "Unable to open the transaction history file." << std::endl;
        return;
    }
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);

    file << "Deposit" << " " << totalCost << " " << std::put_time(now_tm,  "%Y-%m-%d,%H:%M:%S") << " " << getBalance() << " " <<"Stock"<< std::endl;

    if (!file.good()) {
        std::cerr << "Error occurred while writing to the transaction history file." << std::endl;
    }

    file.close(); // Close the file
}
void StockAccount::viewTransactionHistory() {
    std::string filename = "stock_transaction_history.txt";
    std::ifstream file(filename);
    std::string line;

    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::cout << std::left
              << std::setw(10) << "Event"
              << std::setw(15) << "CompSymbol"
              << std::setw(10) << "Number"
              << std::setw(15) << "PricePerShare"
              << std::setw(15) << "TotalValue"
              << std::setw(10) << "Time"
              << std::endl;


    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string event;
        std::string symbol;
        int number;
        double pricePerShare;
        std::string time;

        if (iss >> event >> symbol >> number 
                 >> pricePerShare >> time) {

            std::cout << std::left
              << std::setw(10) << event
              << std::setw(15) << symbol
              << std::setw(10) << number
              << std::setw(15) << pricePerShare
              << '$' << std::setw(15) << number *  pricePerShare
              << std::setw(10) << time
              << std::endl;
            // std::cout << event << " " << symbol << " " 
            //           << number << " $" << pricePerShare << " $" 
            //           << number *  pricePerShare<< " " << time << std::endl;
        }
    }

    file.close();
}

StockAccount::~StockAccount(){
    stockData.addAccountLog(this);

}