// Lower Bound:
// Returns the index of the first element that is
// greater than or equal to x (>= x).

// Example:
// arr = {1, 2, 2, 2, 4, 5}
// x = 2
// lower_bound = 1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &nums, int x)
    {
        int low = 0, high = nums.size() - 1;
        int lower_bound = nums.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x)
            {
                lower_bound = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return lower_bound;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3, 4, 4};
    // cout << arr[0]<<endl;
    cout << s.lowerBound(arr, 2)<<endl;

    return 0;
}