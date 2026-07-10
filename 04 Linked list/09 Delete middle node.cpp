// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// 2095 (Medium) - Delete middle node in ll

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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
        {
            return NULL;
        }
        if (head->next->next == NULL)
        {
            ListNode *temp = head->next;
            head->next = NULL;
            delete (temp);
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        slow->next = NULL;
        delete (slow);
        return head;
    }
};

int main()
{

    return 0;
}