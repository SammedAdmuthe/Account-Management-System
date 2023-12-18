//Author:  Sammed Sunil Admuthe

#include <iostream>
#include "DoublyLinkedList.h"
#include <iomanip>
#include "StockAccount.h"
#include <fstream>
#include <sstream>



DoublyLinkedList::~DoublyLinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = nullptr;
        current = next;
    }
}

void DoublyLinkedList::setSortingStrategy(SortingStrategy* strategy) {
    sortingStrategy = strategy;
}

void DoublyLinkedList::insert(std::string sym, int sh) {
    //check if Symbol Already exists

    ListNode* current = head;
    while (current) {
        if(current->symbol == sym) {
            current->shares+=sh;
            if(current->shares == 0)
            {
                removeNode(sym);
            }
            addStocksToPortfolio();
            
            return;
        }
        current = current->next;
    }

    ListNode* newNode = new ListNode(sym, sh);
    insertInOrder(newNode);
}
void DoublyLinkedList::removeNode(std::string sym){
    ListNode* current = head;

    while (current != nullptr) {
        if (current->symbol == sym) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
            return;
        }
        current = current->next;
    }

}
void DoublyLinkedList::insertInOrder(ListNode* newNode) {
    if (!head) {
        head = tail = newNode;
        addStocksToPortfolio();
        return;
    }
    ListNode* current = head;
    double valuePerShareNew = StockAccount::displayPriceOfStock(newNode->symbol);
    double valuePerShareCurr = StockAccount::displayPriceOfStock(current->symbol);
    while (current && (newNode->shares * valuePerShareNew ) < (current->shares * valuePerShareCurr)) {
        current = current->next;
    }
    if (!current) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) {
            current->prev->next = newNode;
        } else {
            head = newNode;
        }
        current->prev = newNode;
    }
    addStocksToPortfolio();
}
void DoublyLinkedList::addStocksToPortfolio() {
    std::string filename = "Stock_Portfolio_Info.txt";
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    ListNode* current = head;
    while (current != nullptr) {
        outFile << current->symbol << " " << current->shares << std::endl;
        current = current->next;
    }

    outFile.close();
}

void DoublyLinkedList::sortList() {

    std::cout<<"Sorting Portfolio"<<std::endl;

    if (sortingStrategy) {
        sortingStrategy->sort(head);
    }
    // if (!head || !head->next) return;

    // bool swapped;
    // do {
    //     swapped = false;
    //     ListNode* current = head;
    //     while (current->next) {
    //         double valuePerShareCurr = StockAccount::displayPriceOfStock(current->symbol);
    //         double valuePerShareNext = StockAccount::displayPriceOfStock(current->next->symbol);
    //         if ((current->shares * valuePerShareCurr) < (current->next->shares * valuePerShareNext)) {
    //             // Swap the values
    //             std::swap(current->symbol, current->next->symbol);
    //             std::swap(current->shares, current->next->shares);
    //             // std::swap(current->valuePerShare, current->next->valuePerShare);
    //             swapped = true;
    //         }
    //         current = current->next;
    //     }
    // } while (swapped);
}

void DoublyLinkedList::displayCurrentPortfolio(StockAccount& stockAccount) const {
    ListNode* current = head;


    // Displaying Cash balance
    std::cout << "Cash balance = $"<<stockAccount.getBalance() << std::endl;

    // Header
    std::cout << std::left 
              << std::setw(15) << "CompanySymbol" 
              << std::setw(10) << "Number" 
              << std::setw(15) << "PricePerShare" 
              << std::setw(15) << "TotalValue" 
              << std::endl;

    double totalValue = 0.0;
    while (current) {
        double valuePerShare = StockAccount::displayPriceOfStock(current->symbol);
        std::cout << std::left 
            << std::setw(15) << current->symbol 
            << std::setw(10) << current->shares
            << std::setw(15) << valuePerShare
            << std::setw(15) << current->shares * valuePerShare
            << std::endl;
        totalValue += current->shares * valuePerShare;
        current = current->next;
    }
    std::cout<<"Total portfolio value: $"<<totalValue + stockAccount.getBalance()<<std::endl;
}
int DoublyLinkedList::getShares(std::string symbol){
    ListNode* current = head;
    while (current) {
        if(current->symbol == symbol) {
            
            return current->shares;
        }
        current = current->next;
    }
    return -1;
}

void DoublyLinkedList::addAccountLog(StockAccount *stockAccount) {
    std::string filename = "accountLog.txt";
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Unable to open the file: " << filename << std::endl;
        return;
    }

    ListNode* current = head;
    double totalPortfolioValue = 0.0;
    while (current != nullptr) {
        totalPortfolioValue += current->shares * StockAccount::displayPriceOfStock(current->symbol);
        current = current->next;
    }
    totalPortfolioValue+=stockAccount->getBalance();
    // Get the current date and time
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    file << totalPortfolioValue <<" "<<stockAccount->getBalance() <<" "<<asctime(now_tm);
    // Write the date, time, portfolio value, and cash balance to the file

    file.close();
}

// int main() {
//     DoublyLinkedList dll;
//     dll.insert("AAPL", 10);
//     dll.insert("GOOG", 20);
//     dll.insert("MSFT", 30);
//     dll.display();
//     return 0;
// }






