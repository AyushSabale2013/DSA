// https://leetcode.com/problems/max-consecutive-ones/
// 485 (Easy) - Max consecutive ones in subarray

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int total = 0;
        int ans = 0;
        for (auto num : nums)
        {
            if (num == 1)
            {
                total++;
            }
            else
            {
                if (total > ans)
                {
                    ans = total;
                }
                total = 0;
            }
        }
        if (total > ans)
        {
            ans = total;
        }

        return ans;
    }
};

int main()
{

    return 0;
}