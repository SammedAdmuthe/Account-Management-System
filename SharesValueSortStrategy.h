// Authors: Sammed Sunil Admuthe

#ifndef SHARESVALUESORTSTRATEGY_H
#define SHARESVALUESORTSTRATEGY_H

#include <iostream>
#include "SortingStrategy.h"
#include "DoublyLinkedList.h"
#include "StockAccount.h"
#include "ListNode.h"
#include <iomanip>


// Uses bubble sort as a Strategy to sort by shares * valuePerShare
class SharesValueSortStrategy : public SortingStrategy {
public:
    void sort(ListNode* head) override {
        if (!head || !head->next) return;

        bool swapped;
        do {
            swapped = false;
            ListNode* current = head;
            while (current->next) {
                double valuePerShareCurr = StockAccount::displayPriceOfStock(current->symbol);
                double valuePerShareNext = StockAccount::displayPriceOfStock(current->next->symbol);
                if ((current->shares * valuePerShareCurr) < (current->next->shares * valuePerShareNext)) {
                    // Swap the values
                    std::swap(current->symbol, current->next->symbol);
                    std::swap(current->shares, current->next->shares);
                    // std::swap(current->valuePerShare, current->next->valuePerShare);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);

        ListNode* current = head;
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

    ~SharesValueSortStrategy(){}

};

#endif