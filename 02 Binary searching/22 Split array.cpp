// https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z
// 410 (hard) - Split array according to largest sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sum(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        return sum;
    }

    bool isSplitPossible(vector<int> &nums, int k, long long largest)
    {
        int subarraysUsed = 1;
        int subArraySum = 0;

        for (int num : nums)
        {
            if (subArraySum + num <= largest)
            {
                subArraySum += num;
            }
            else
            {
                subarraysUsed++;
                subArraySum = num;
                if (subarraysUsed > k)
                {
                    return false;
                }
            }
        }

        return subarraysUsed <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = sum(nums);
        long long ans = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (isSplitPossible(nums, k, mid))
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
    vector<int> arr = {7, 2, 5, 10, 8};
    Solution s;
    cout << s.splitArray(arr, 2)
         << endl;

    return 0;
}