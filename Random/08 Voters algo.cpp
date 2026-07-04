// https://leetcode.com/problems/majority-element/
// 169 (Easy) - Majority element

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int majority = 0;
        int low = 0, high = static_cast<int>(nums.size());

        while (low < high)
        {
            if (nums[low] == nums[majority])
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count < 0)
            {
                majority = low;
                count = 0;
            }

            low++;
        }

        return nums[majority];
    }
};

int main()
{

    return 0;
}