// Authors: Sammed Sunil Admuthe

#ifndef SYMBOL_SORT_STRATEGY_H
#define SYMBOL_SORT_STRATEGY_H

#include "SortingStrategy.h"
#include "DoublyLinkedList.h"
#include "StockAccount.h"

// Uses selection sort as a Strategy to sort by symbol
class SymbolSortStrategy : public SortingStrategy {
public:
    void sort(ListNode* head) override {
        if (!head || !head->next) return;
        std::cout << "Sorting by symbol" << std::endl;

        ListNode* current = head;
        while (current) {
            ListNode* minNode = findMinBySymbol(current);
            if (minNode != current) {
                // Swap the values
                std::swap(current->symbol, minNode->symbol);
                std::swap(current->shares, minNode->shares);
            }
            current = current->next;
        }

        current = head;
        std::cout << std::left 
            << std::setw(15) << "CompanySymbol" 
            << std::setw(10) << "Number" 
            << std::setw(15) << "PricePerShare" 
            << std::setw(15) << "TotalValue" 
            << std::endl;
        while(current) {
            double valuePerShare = StockAccount::displayPriceOfStock(current->symbol);
            std::cout << std::left 
                << std::setw(15) << current->symbol
                << std::setw(10) << current->shares
                << std::setw(15) << valuePerShare
                << std::setw(15) << current->shares * valuePerShare
                << std::endl;
            current = current->next;
        }
    }
    ListNode* findMinBySymbol(ListNode* start) {
        ListNode* minNode = start;
        ListNode* current = start->next;
        while (current) {
            if (current->symbol < minNode->symbol) {
                minNode = current;
            }
            current = current->next;
        }
        return minNode;
    }

    ~SymbolSortStrategy(){}

};

#endif