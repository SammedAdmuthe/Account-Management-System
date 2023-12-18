#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>
class ListNode {
public:
    std::string symbol;
    int shares;
    ListNode* next;
    ListNode* prev;

    ListNode(std::string sym, int sh) 
        : symbol(sym), shares(sh), next(nullptr), prev(nullptr) {}
    ~ListNode(){} 
};
#endif