// https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18
// 3471 (Easy) Find largest number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkUnique(vector<int> &nums, int ele)
    {
        int count = 0;
        for (int num : nums)
        {
            if (num == ele)
            {
                count++;
            }
            if (count == 2)
            {
                return false;
            }
        }
        return true;
    }
    int largestInteger(vector<int> &nums, int k)
    {
        int ans = -1;
        if (k == 1)
        {
            for (int ele : nums)
            {
                if (ele > ans)
                {
                    if (checkUnique(nums, ele))
                    {
                        ans = ele;
                    }
                }
            }
            return ans;
        }
        if (k == nums.size())
        {
            ans = *max_element(nums.begin(), nums.end());
            return ans;
        }

        int first = nums[0];
        int last = nums[nums.size() - 1];
        bool isfirst = checkUnique(nums, first);
        bool islast = checkUnique(nums, last);
        if (isfirst == true && islast == true)
        {
            if (first > last)
            {
                return first;
            }
            return last;
        }
        else if (isfirst == true && islast == false)
        {
            return first;
        }
        else if (isfirst == false && islast == true)
        {
            return last;
        }
        return ans;
    }
};

int main()
{

    return 0;
}