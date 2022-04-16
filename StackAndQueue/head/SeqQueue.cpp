#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <unordered_map>
#include "SeqQueue.h"
#include "ListNode.h"
SeqQueueNode::SeqQueueNode()
{
    Last = new ListNode();
}
SeqQueueNode::SeqQueueNode(int val)
{
    Last = new ListNode();
    Last->val = val;
    Last->next = Last;
}

int SeqQueueNode::getLast()
{
    if (!Last->next)
    {
        std::cout << "The Last is empty." << std::endl;
        throw 2;
    }
    return Last->next->val;
}

void SeqQueueNode::getAll()
{
    auto curr = Last->next;
    while (curr!=Last)
    {
        std::cout << curr->val << ' ';
        curr = curr->next;
    }
    std::cout << curr->val << std::endl;
}

int SeqQueueNode::getHead()
{
    if (!Last->next)
    {
        std::cout << "The Last is empty." << std::endl;
        throw 2;
    }
    return Last->val;
}


void SeqQueueNode::inQueueNode(int val)
{
    if (!Last->next)
    {
        Last->val = val;
        Last->next = Last;
        return;
    }
    else {
        ListNode* curr = new ListNode(val, Last->next);
        Last->next = curr;
        Last = Last->next;
    }
}

void SeqQueueNode::outQueueNode()
{
    if (Last->next == nullptr) {
        std::cout << "This queue is empty" << std::endl;
        return;
    }
    if (Last->next == Last) {
        Last->next = nullptr;
    }
    else
    {
        auto curr = Last->next;
        Last->next = Last->next->next;
        delete(curr);
    }
}

bool SeqQueue::isFull()
{
    return (last+1)%MaxNum==head;
}

bool SeqQueue::isEmpty()
{
    return head==last;
}

void SeqQueue::inQueue(int val)
{
    if (isFull()) {
        std::cout << "The queue is empty!" << std::endl;
        return;
    }
    element[last] = val;
    last = (last + 1) % MaxNum;
}

void SeqQueue::outQueue()
{
    if (isEmpty()) {
        std::cout << "This queue is empty!" << std::endl;
        return;
    }
    head = (head + 1) % MaxNum;
}

int SeqQueue::getHead()
{
    if (isEmpty()) {
        std::cout << "This queue is empty!" << std::endl;
        throw 2;
    }
    return element[head];
}

int SeqQueue::length()
{
    return (last+MaxNum-head)%MaxNum;
}

void SeqQueue::getAll()
{
    for (int i = head; i < head + length(); i++) {
        std::cout << element[i % MaxNum] << ' ';
    }
    std::cout << '\n';
}
