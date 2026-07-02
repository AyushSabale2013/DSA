// https://leetcode.com/problems/binary-search/
// Ques no. 704 Binary Searching


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;

        while (i <= j)
        {
            int mid = i - (i - j) / 2 ;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}
