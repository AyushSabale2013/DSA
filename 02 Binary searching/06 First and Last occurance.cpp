// First and last occurrence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};
        int lb = nums.size(), ub = nums.size();
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                high = mid - 1;
                lb = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        low = 0;
        high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                ub = mid;
                low = mid + 1;
            }
        }

        if (lb != nums.size() && nums[lb] == target)
        {
            ans[0] = lb;
            ans[1] = lb;
        }
        if (ub != nums.size() && nums[ub] == target)
        {
            ans[1] = ub;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    vector<int> ans = s.searchRange(arr, 7);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}