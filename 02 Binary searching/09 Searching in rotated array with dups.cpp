// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// 81 searching in rotated array with duplicates (medium)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = static_cast<int>(nums.size()) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] == nums[low])
            {
                low++;
                continue;
            }
            else if (nums[mid] >= nums[low])
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && nums[high] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 0, 1, 1, 1};

    cout << s.search(arr, 0) << endl;
    return 0;
}