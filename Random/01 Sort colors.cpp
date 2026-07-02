// https://leetcode.com/problems/sort-colors/submissions/2042208031/
// 75 (medium) - Dutch national flag algorithm color sorting

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (mid < static_cast<int>(nums.size()))
        {
            if (nums[mid] == 0 && mid >= low)
            {
                swap(nums[mid], nums[low]);
                low++;
            }
            else if (nums[mid] == 2 && mid <= high)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};

int main()
{
    vector<int> arr = {1, 2, 0};
    Solution s;
    s.sortColors(arr);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}