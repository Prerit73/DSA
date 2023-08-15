
#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        ListNode(0);
    }
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

ListNode *partition(ListNode *head, int x)
{

    ListNode *greaterHead = new ListNode(-1);
    ListNode *lessHead = new ListNode(-1);
    ListNode *tail = head, *greaterTail = greaterHead, *lessTail = lessHead;

    while (tail)
    {
        if (tail->val < x)
        {
            lessTail->next = tail;
            lessTail = lessTail->next;
        }
        else
        {
            greaterTail->next = tail;
            greaterTail = greaterTail->next;
        }

        tail = tail->next;
    }
    greaterTail->next = NULL;
    lessTail->next = greaterHead->next;
    return lessHead->next;
};