// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// 160 (Easy) Intersection of two linked list

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
    int sizeOfLL(ListNode *head)
    {
        ListNode *temp = head;
        int ans = 0;
        while (temp != NULL)
        {
            ans++;
            temp = temp->next;
        }

        return ans;
    }
    ListNode *Equilizer(ListNode *head, int diff)
    {
        ListNode *temp = head;
        for (int i = 0; i < diff; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int sizeA = sizeOfLL(headA);
        int sizeB = sizeOfLL(headB);
        int diff = sizeA - sizeB;
        ListNode *left;
        ListNode *right;
        if (diff >= 0)
        {
            left = Equilizer(headA, diff);
            right = headB;
        }
        else
        {
            diff *= -1;
            left = headA;
            right = Equilizer(headB, diff);
        }

        ListNode *ans = NULL;
        while (left != NULL)
        {
            if (left == right)
            {
                ans = left;
                break;
            }
            left = left->next;
            right = right->next;
        }
        return ans;
    }
};

int main()
{

    return 0;
}