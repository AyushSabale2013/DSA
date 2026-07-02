
// https://leetcode.com/problems/search-insert-position/description/
// 34 Search insert position

// Floor:
// The largest element in the array that is <= target.
// Example:
// arr = [1, 3, 5, 7]
// target = 6
// floor = 5

// Ceil:
// The smallest element in the array that is >= target.
// Example:
// arr = [1, 3, 5, 7]
// target = 6
// ceil = 7

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {
        vector<int> ans = {-1, -1};
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == x)
            {
                ans[0] = x;
                ans[1] = x;
                return ans;
            }
            else if (x > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (high >= 0)
        {
            ans[0] = nums[high];
        }
        if (low < nums.size())
        {
            ans[1] = nums[low];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    vector<int> ans = s.getFloorAndCeil(arr, 8);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}