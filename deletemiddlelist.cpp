#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *deleteMiddle(ListNode *head)
{
    ListNode *ptr = head;
    int c = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        c++;
    }
    if (c == 1)
    {
        return NULL;
    }
    int i = c / 2;
    ListNode *temp = head;
    ListNode *p = temp->next;
    int cnt = 0;
    while (cnt != i - 1)
    {
        temp = temp->next;
        p = p->next;
        cnt++;
    }
    temp->next = p->next;
    delete p;
    return head;
}
