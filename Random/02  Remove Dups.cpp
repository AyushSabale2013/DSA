// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// 26 (easy) - REmove duplicates from sorted array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int unique = 0;
        int low = 0;
        while (low < static_cast<int>(nums.size()))
        {
            if (nums[low] != nums[unique])
            {
                unique++;
                nums[unique] = nums[low];
            }
            low++;
        }

        return ++unique;
    }
};

int main()
{
    vector<int> arr = {0, 1, 2, 2, 2, 2, 2, 3, 3, 4 , 5};
    Solution s;
    cout << s.removeDuplicates(arr) << endl;

    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}