// https://leetcode.com/problems/add-two-numbers/description/
// 2 (Medium) Add two numbers in form of ll

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

    ListNode *findLongest(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        while (temp1 != NULL && temp2 != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == NULL)
        {
            return l2;
        }
        else
        {
            return l1;
        }
    }

    void addLongestcarry(ListNode *position)
    {
        while (position->next != NULL && position->val == 9)
        {
            position->val = 0;
            position = position->next;
        }
        if (position->val != 9)
        {
            position->val += 1;
        }
        else
        {
            position->val = 0;
            ListNode *newnode = new ListNode(1);
            position->next = newnode;
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int isCarry = 0;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *Longest = findLongest(l1, l2);
        ListNode *ans = Longest;

        while (temp1->next != NULL && temp2->next != NULL)
        {
            if (temp1->val + temp2->val + isCarry >= 10)
            {
                Longest->val = temp1->val + temp2->val + isCarry - 10;
                isCarry = 1;
            }
            else
            {
                Longest->val = temp1->val + temp2->val + isCarry;
                isCarry = 0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            Longest = Longest->next;
        }

        if (temp1->next == NULL && temp2->next == NULL)
        {
            if (temp1->val + temp2->val + isCarry >= 10)
            {
                Longest->val = temp1->val + temp2->val + isCarry - 10;
                isCarry = 1;
            }
            else
            {
                Longest->val = temp1->val + temp2->val + isCarry;
                isCarry = 0;
            }
            if (isCarry)
            {
                ListNode *newnode = new ListNode(1);
                Longest->next = newnode;
            }
        }
        else
        {
            if (temp1->val + temp2->val + isCarry >= 10)
            {
                Longest->val = temp1->val + temp2->val + isCarry - 10;
                isCarry = 1;
            }
            else
            {
                Longest->val = temp1->val + temp2->val + isCarry;
                isCarry = 0;
            }
            if (isCarry)
            {
                addLongestcarry(Longest->next);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}