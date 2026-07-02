// https://leetcode.com/problems/reverse-linked-list/description/
// 206 (Easy) - Reverse linked list

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *reserveHead = head;
        ListNode *newHead = NULL;
        while (temp != NULL)
        {
            reserveHead = temp->next;
            temp->next = newHead;
            newHead = temp;
            temp = reserveHead;
        }

        return newHead;
    }
};

int main()
{

    return 0;
}