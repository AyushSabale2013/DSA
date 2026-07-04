// https://leetcode.com/problems/odd-even-linked-list/description/
// 328 (Medium) Even odd Linked list

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *findTail(ListNode *head)
    {
        ListNode *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        return tail;
    }
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return head;
        }
        ListNode *tail = findTail(head);
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *savepoint = tail;
        while (odd->next != savepoint && odd != savepoint)
        {
            odd->next = even->next;
            even->next = NULL;
            tail->next = even;
            tail = tail->next;
            odd = odd->next;
            even = odd->next;
        }
        if (odd->next != savepoint)
        {
            odd->next = even->next;
            even->next = NULL;
            tail->next = even;
            tail = tail->next;
            odd = odd->next;
            even = odd->next;
        }
        

        return head;
    }
};

void printLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Solution s;

    ListNode temp1(1);
    ListNode temp2(2);
    ListNode temp3(3);
    ListNode temp4(4);
    ListNode temp5(5);
    temp1.next = &temp2;
    temp2.next = &temp3;
    temp3.next = &temp4;
    temp4.next = &temp5;
    temp5.next = NULL;
    printLL(&temp1);
    cout << "After operation" << endl;
    printLL(s.oddEvenList(&temp1));

    return 0;
}