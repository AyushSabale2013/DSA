// https://takeuforward.org/plus/dsa/problems/add-one-to-a-number-represented-by-ll?source=strivers-a2z-dsa-track

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
   
    ListNode *addOne(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *reversedLL = reverseLL(head);
        ListNode *temp = reversedLL;
        ListNode *prev;
        while (temp != NULL && temp->val == 9)
        {
            temp->val = 0;
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            temp->val += 1;
        }
        else
        {
            ListNode *newnode = new ListNode(1);
            prev->next = newnode;
        }
        return reverseLL(reversedLL);
    }
};

int main()
{

    return 0;
}