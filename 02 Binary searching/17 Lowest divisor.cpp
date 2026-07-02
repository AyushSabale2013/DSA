// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// 1283 Smallest divisor in given threshold

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAns(vector<int> &nums, int threshold, int divisor)
    {
        int sum = 0;
        for (int ele : nums)
        {
            if (!(ele % divisor))
            {
                sum += ele / divisor;
            }
            else
            {
                sum += 1 + (ele / divisor);
            }
        }
        if (sum <= threshold)
        {
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (checkAns(nums, threshold, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }


        return ans;
    }
};

int main()
{
    vector<int> arr = {44,22,33,11,1};
    Solution s;
    cout << s.smallestDivisor(arr, 5)
         << endl;

    return 0;
}