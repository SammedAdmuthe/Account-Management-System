// Authors: Sammed Sunil Admuthe


#ifndef SORTINGSTRATEGY_H
#define SORTINGSTRATEGY_H

#include "DoublyLinkedList.h"
#include "ListNode.h"

class SortingStrategy {
public:
    virtual void sort(ListNode* head) = 0;
    virtual ~SortingStrategy() {}
};

#endif