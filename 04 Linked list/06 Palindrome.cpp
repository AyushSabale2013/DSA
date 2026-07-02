// https://leetcode.com/problems/palindrome-linked-list/
// 234 (Easy) - check palindrome or not

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode *modify(ListNode *head)
    {
        if (head->next == NULL)
        {
            return head;
        }
        else if (head->next->next == NULL)
        {
            return head->next;
        }

        ListNode *middle = findMiddle(head);
        ListNode *temp = middle->next;
        ListNode *reserveHead = temp->next;
        middle->next = NULL;

        while (temp != NULL)
        {
            temp->next = middle;
            middle = temp;
            temp = reserveHead;
            if (temp != NULL)
            {
                reserveHead = temp->next;
            }
        }

        return middle;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *left = head;
        ListNode *right = modify(head);
        while (right != NULL && left != NULL)
        {
            if (left->val != right->val)
            {
                return false;
            }

            left = left->next;
            right = right->next;
        }
        return true;
    }
};

int main()
{

    return 0;
}