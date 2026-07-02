// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 153 Finding minimum in rotated sored array (medium)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = static_cast<int>(nums.size()) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= nums[low] && nums[mid] <= nums[high])
            {
                break;
            }
            else if (nums[mid] >= nums[low] && nums[mid] >= nums[high])
            {
                // left sorted
                low = mid + 1;
            }
            else if (nums[mid] <= nums[low] && nums[mid] <= nums[high])
            {
                // right sorted
                high = mid;
            }
        }
        return nums[low];
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3,1,2};

    cout << s.findMin(arr) << endl;
    return 0;
}