// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/
// 1413 (Easy) - Minimum value of step by step sum;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkWhole(vector<int> &nums)
    {
        for (auto num : nums)
        {
            if (num < 0)
            {
                return false;
            }
        }
        return true;
    }
    int minStartValue(vector<int> &nums)
    {
        int startValue = 1;
        if (checkWhole(nums))
        {
            return startValue;
        }

        int low = 0, high = static_cast<int>(nums.size());
        int sum = startValue;
        while (low < high)
        {
            if (sum + nums[low] < 1)
            {
                startValue += (-1) * (sum + nums[low]) + 1;
                sum = 1;
            }
            else
            {
                sum += nums[low];
            }

            low++;
        }

        return startValue;
    }
};

int main()
{

    return 0;
}