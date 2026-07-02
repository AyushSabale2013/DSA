// https://leetcode.com/problems/search-in-rotated-sorted-array/
// 33 searching in rotated array (medium)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = static_cast<int>(nums.size()) - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] >= nums[low])
            {
                if (target < nums[mid] && target >= nums[low])
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
                if (target > nums[mid] && target <= nums[high])
                {

                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {4 , 5 , 6 , 7 , 0 , 1 , 2 , 3};

    cout << s.search(arr, 11) << endl;
    return 0;
}