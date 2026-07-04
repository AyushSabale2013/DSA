// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// 19 (Medium) - Remove Nth node from   LinkedList

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
    int sizeOfLL(ListNode *head)
    {
        int sz = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            sz++;
            temp = temp->next;
        }

        return sz;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        n = (sizeOfLL(head) + 1) - n;
        if (n == 1)
        {
            if (head->next != NULL)
            {
                ListNode *temp = head;
                head = head->next;
                temp->next = NULL;
                delete (temp);
                return head;
            }
            else
            {
                delete (head);
                return NULL;
            }
        }

        ListNode *prev = head;
        for (int i = 1; i <= (n - 2); i++)
        {
            prev = prev->next;
        }
        ListNode *target = prev->next;
        prev->next = target->next;
        target->next = NULL;
        delete (target);

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
    cout << "After deletion : " << endl;
    printLL(s.removeNthFromEnd(&temp1, 2));

    return 0;
}