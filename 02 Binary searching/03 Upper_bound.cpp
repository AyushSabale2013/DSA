// Upper Bound:
// Returns the index of the first element that is
// strictly greater than x (> x).

// Example:
// arr = {1, 2, 2, 2, 4, 5}
// x = 2
// upper_bound = 4

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &nums, int x)
    {

        int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
                ans = mid;
            }
        }

        return ans + 1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 2, 3};
    // cout << arr[0]<<endl;
    cout << s.upperBound(arr, 2) << endl;

    return 0;
}