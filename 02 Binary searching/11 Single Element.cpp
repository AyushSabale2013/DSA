// https://leetcode.com/problems/single-element-in-a-sorted-array/
// 540 find single element in array where array contains exactly two duplicates of each number exacept single one

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = static_cast<int>(nums.size()) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int original = (high - low + 2) / 2;
            if (low == high)
            {
                break;
            }
            else if (original % 2 == 0)
            {
                if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                {
                    return nums[mid];
                }
                else if (nums[mid] == nums[mid + 1])
                {
                    high = mid - 1;
                }
                else if (nums[mid] == nums[mid - 1])
                {
                    low = mid + 1;
                }
            }
            else if (original % 2 != 0)
            {
                if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                {
                    return nums[mid];
                }
                else if (nums[mid] == nums[mid + 1])
                {
                    low = mid + 2;
                }
                else if (nums[mid] == nums[mid - 1])
                {
                    high = mid - 2;
                }
            }
        }

        return nums[low];
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3,3,7,7,10,11,11};

    cout << s.singleNonDuplicate(arr) << endl;
    return 0;
}