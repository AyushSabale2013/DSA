// https://leetcode.com/problems/sort-list/description/
// 148 (Medium) - Sort linked list
// Same question using merge sort

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
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left && right)
        {
            if (left->val <= right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left)
            tail->next = left;
        else
            tail->next = right;

        return dummy.next;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* mid = findMid(head);

        // Split list
        ListNode* second = mid->next;
        mid->next = NULL;

        // Sort both halves
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(second);

        // Merge
        return merge(left, right);
    }

    ListNode* sortList(ListNode* head)
    {
        return mergeSort(head);
    }
};


int main()
{

    return 0;
}