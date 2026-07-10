// https://leetcode.com/problems/sort-list/description/
// 148 (Medium) - Sort linked list

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
        ListNode *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    ListNode *sortList(ListNode *head)
    {
        int LengthOfLL = sizeOfLL(head);
        vector<long> mapped(LengthOfLL);
        ListNode *temp = head;
        int low = 0;
        while (temp != NULL)
        {
            mapped[low] = temp->val;
            temp = temp->next;
            low++;
        }
        sort(mapped.begin(), mapped.end());
        temp = head;
        low = 0;
        while (temp != NULL)
        {
            temp->val = mapped[low];
            temp = temp->next;
            low++;
        }

        return head;
    }
};

int main()
{

    return 0;
}