// https://takeuforward.org/plus/dsa/problems/delete-all-occurrences-of-a-key-in-dll?source=strivers-a2z-dsa-track

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    ListNode *deleteAllOccurrences(ListNode *head, int target)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->val == target)
            {
                if (temp->prev != NULL && temp->next != NULL)
                {
                    ListNode *desired = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp = temp->next;
                    delete (desired);
                }
                else if (temp->prev == NULL && temp->next == NULL)
                {
                    return NULL;
                }
                else if (temp->prev == NULL)
                {
                    ListNode *desired = temp;
                    temp->next->prev = temp->prev;
                    temp = temp->next;
                    delete (desired);
                }
                else
                {
                    ListNode *desired = temp;
                    temp->prev->next = temp->next;
                    temp = temp->next;
                    delete (desired);
                }
            }
        }

        return head;
    }
};

int main()
{

    return 0;
}