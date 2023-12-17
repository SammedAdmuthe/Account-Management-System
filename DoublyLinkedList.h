//Author:  Sammed Sunil Admuthe

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string>
class StockAccount;

class ListNode {
public:
    std::string symbol;
    int shares;
    ListNode* next;
    ListNode* prev;

    ListNode(std::string sym, int sh) 
        : symbol(sym), shares(sh), next(nullptr), prev(nullptr) {}
        
};

class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;

    void insertInOrder(ListNode* newNode);
    void removeNode(ListNode* node);
    void swapNodes(ListNode* node1, ListNode* node2);

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();

    void insert(std::string sym, int sh);
    void sortList();
    void displayCurrentPortfolio(StockAccount &stockAccount) const;
    void addStocksToPortfolio();
    int getShares(std::string symbol);
    void removeNode(std::string symbol);
    void addAccountLog(StockAccount *stockAccount);
};
#endif // DOUBLYLINKEDLIST_H
