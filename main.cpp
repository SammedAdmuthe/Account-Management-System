//Author:  Sammed Sunil Admuthe

#include "StockAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>
#include "BankAccount.h"


using namespace std;

int main() {
    int accountType;
    cout << "Welcome to the Account Management System." << endl;
    // Bank Withdrawal
    StockAccount stockAccount(10000);
    BankAccount bankAccount(10000);
    do {
        cout << "Please select an account to access:" << endl;
        cout << "1. Stock Portfolio Account" << endl;
        cout << "2. Bank Account" << endl;
        cout << "3. Exit" << endl ;
        cout << endl;
        cout<< "Option: ";
        std::cin >> accountType;
        cout << endl;
        switch (accountType)
        {
            case 1:
            {

                int option;

                do {
                    cout << "Please select an option:" << endl;
                    cout << "1. Display the price for a stock symbol" << endl;
                    cout << "2. Display the current portfolio" << endl;
                    cout << "3. Buy Shares" << endl;
                    cout << "4. Sell Shares" << endl;
                    cout << "5. View a graph for the portfolio value" << endl;
                    cout << "6. View transaction history" << endl;
                    cout << "7. Return to previous menu" << endl;
                    cout << endl;
                    cout << "Option: ";
                    std::cin >> option;
                    cout << endl;

                    switch (option)
                    {
                        case 1:
                        {
                            //1. Display the price of a stock
                            cout<<"Enter Stock Symbol to view current price: "<<endl;
                            string sym;
                            std::cin>>sym;


                            std::cout<<"Displaying current price of stock: "<<std::endl;
                            double getCurrentStockPrice = StockAccount::displayPriceOfStock(sym);
                            if(getCurrentStockPrice != 0.0) {

                                std::cout << std::left << std::setw(15) << "Company-Symbol" 
                                      << std::setw(10) << "Price per share" << std::endl;

                                std::cout << std::left << std::setw(15) << sym <<"$" 
                                      << std::setw(10) << StockAccount::displayPriceOfStock(sym) << std::endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            //2. Display the current portfolio
                            std::cout<<"Displaying current portfolio: "<<std::endl;
                            stockAccount.displayCurrentPortfolio();
                            break;
                        }
                        case 3:
                        {
                            // 3. Buy shares
                            string symb;
                            std::cout<<"Please enter the stock symbol you wish to purchase: "<<std::endl;
                            std::cin>>symb;
                            int no_shares=0;
                            double amount;
                            std::cout<<"Please enter the number of shares:"<<std::endl;
                            std::cin>>no_shares;
                            std::cout<<"Please enter the maximum amount you are willing to pay per share: "<<std::endl;
                            std::cin>>amount;
                            stockAccount.buyShares(symb, no_shares, amount);
                            break;
                        }
                        case 4:
                        {
                            //4. Sell shares
                            string symb;
                            std::cout<<"Please enter the stock symbol you wish to sell: "<<std::endl;
                            std::cin>>symb;
                            int no_shares=0;
                            double amount;
                            std::cout<<"Please enter the number of shares:"<<std::endl;
                            std::cin>>no_shares;

                            std::cout<<"Please enter the minimum amount you are willing to sell each share of stock: "<<std::endl;
                            std::cin>>amount;
                            stockAccount.sellShares(symb, no_shares, amount);    
                            break;
                        }
                        case 5:
                        {
                            system("Rscript plot.R");
                            break;
                        }
                        case 6:
                        {
                            stockAccount.viewTransactionHistory();
                            break;
                        }
                        case 7:
                        {
                            break;
                        }                
                        default:
                            break;
                    }
                } while (option < 7);
                break;
            }
            case 2:
            {

                int option;

                do {
                    cout << "Please select an option:" << endl;
                    cout << "1. View account balance" << endl;
                    cout << "2. Deposit money" << endl;
                    cout << "3. Withdraw money" << endl;
                    cout << "4. Print out history" << endl;
                    cout << "5. Return to previous menu" << endl;
                    cout << endl;
                    cout << "Option: ";
                    std::cin >> option;
                    cout << endl;

                    switch (option)
                    {
                        case 1:
                        {
                            bankAccount.accountBalance();
                            break;
                        }
                        case 2:
                        {
                            double amount;
                            std::cout<<"Please select the amount you wish to deposit: "<<std::endl;
                            std::cin>>amount;
                            bankAccount.deposit(amount);    
                            break;
                        }
                        case 3:
                        {
                            double amount;
                            std::cout<<"Please select the amount you wish to withdraw: "<<std::endl;
                            std::cin>>amount;
                            bankAccount.withdraw(amount);
                            break;
                        }
                        case 4:
                        {
                            bankAccount.viewBankTransactionHistory();
                            break;
                        }
                        case 5:
                        {
                            break;
                        }         
                        default:
                            break;
                    }
                } while (option < 5);
                break;
            }
            default:
                break;
        }
    }while (accountType < 3);

    return 0;
}
