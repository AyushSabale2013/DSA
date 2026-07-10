// https://takeuforward.org/plus/dsa/problems/sort-a-ll-of-0's-1's-and-2's?source=strivers-a2z-dsa-track

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *&head)
    {
        ListNode *zeros = NULL;
        ListNode *zeros_head = NULL;
        ListNode *ones = NULL;
        ListNode *ones_head = NULL;
        ListNode *twos = NULL;
        ListNode *twos_head = NULL;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                if (zeros == NULL)
                {
                    zeros = temp;
                    zeros_head = zeros;
                    temp = temp->next;
                    zeros->next = NULL;
                }
                else
                {
                    zeros->next = temp;
                    zeros = zeros->next;
                    temp = temp->next;
                    zeros->next = NULL;
                }
            }
            else if (temp->data == 1)
            {
                if (ones == NULL)
                {
                    ones = temp;
                    ones_head = ones;
                    temp = temp->next;
                    ones->next = NULL;
                }
                else
                {
                    ones->next = temp;
                    ones = ones->next;
                    temp = temp->next;
                    ones->next = NULL;
                }
            }
            else
            {
                if (twos == NULL)
                {
                    twos = temp;
                    twos_head = twos;
                    temp = temp->next;
                    twos->next = NULL;
                }
                else
                {
                    twos->next = temp;
                    twos = twos->next;
                    temp = temp->next;
                    twos->next = NULL;
                }
            }
        }
        if (zeros_head != NULL)
        {
            temp = zeros_head;
            if (ones_head != NULL)
            {
                zeros->next = ones_head;
                if (twos_head != NULL)
                {
                    ones->next = twos_head;
                }
                else
                {
                    ones->next = NULL;
                }
            }
            else
            {
                if (twos_head != NULL)
                {
                    zeros->next = twos_head;
                    twos->next = NULL;
                }
                else
                {
                    zeros->next = NULL;
                }
            }
        }
        else
        {
            if (ones_head != NULL)
            {
                temp = ones_head;
                if (twos_head != NULL)
                {
                    ones->next = twos_head;
                    twos->next = NULL;
                }
                else
                {
                    ones->next = NULL;
                }
            }
            else
            {
                if (twos_head != NULL)
                {
                    temp = twos_head;
                    twos->next = NULL;
                }
            }
        }


        return temp;
    }
};

int main()
{

    return 0;
}