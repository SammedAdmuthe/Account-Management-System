//Author:  Sammed Sunil Admuthe
#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>


BankAccount::BankAccount(double initialBalance){
    if(getBalance() == -1)
    {
        setBalance(initialBalance);
    }

}

void BankAccount::deposit(double amount) {
    setBalance(getBalance() + amount);
    recordBankTransaction("Deposit", amount);
}
void BankAccount::accountBalance() {
    std::cout<< "Account balance is : "<< getBalance() << std::endl;
}

void BankAccount::viewBankTransactionHistory() {
    std::string filename = "bank_transaction_history.txt";
    std::ifstream file(filename);
    std::string line;

    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::cout << std::left
              << std::setw(15) << "Event"
              << std::setw(15) << "Amount"
              << std::setw(30) << "Date"
              << std::setw(15) << "Balance"
              << std::endl;


    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string event;
        double amount;
        std::string date;
        double balance;

        if (iss >> event >> amount >> date 
                 >> balance) {

            std::cout << std::left
              << std::setw(15) << event
              << std::setw(15) << amount
              << std::setw(30) << date
              << std::setw(15) << balance
              << std::endl;
        }
    }

    file.close();
}

void BankAccount::recordBankTransaction(std::string event, double amount) {
    std::ofstream file("bank_transaction_history.txt", std::ios::app); 

    if (!file) {
        std::cerr << "Unable to open the transaction history file." << std::endl;
        return;
    }
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);

    file << event << " " << amount << " " <<  std::put_time(now_tm, "%Y-%m-%d,%H:%M:%S") << " " << getBalance() << " " << std::endl;

    if (!file.good()) {
        std::cerr << "Error occurred while writing to the transaction history file." << std::endl;
    }

    file.close(); // Close the file
}

void BankAccount::withdraw(double amount) {
    if (amount > getBalance()) {
        std::cout << "Error: Insufficient funds." << std::endl;
        return;
    }
    setBalance(getBalance() - amount);
    recordBankTransaction("Withdrawal", amount);
}