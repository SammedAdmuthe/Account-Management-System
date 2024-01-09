//Author:  Sammed Sunil Admuthe

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string>
#include "SortingStrategy.h"
#include "ListNode.h"
class StockAccount;



class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;
    SortingStrategy* sortingStrategy;
    void insertInOrder(ListNode* newNode);
    void removeNode(ListNode* node);
    void swapNodes(ListNode* node1, ListNode* node2);

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();
    void setSortingStrategy(SortingStrategy* strategy);
    void insert(std::string sym, int sh);
    void sortList();
    void displayCurrentPortfolio(StockAccount &stockAccount) const;
    void addStocksToPortfolio();
    int getShares(std::string symbol);
    void removeNode(std::string symbol);
    void sortByTotalValue();
    void addAccountLog(StockAccount *stockAccount);
    void display();
};
#endif // DOUBLYLINKEDLIST_H
