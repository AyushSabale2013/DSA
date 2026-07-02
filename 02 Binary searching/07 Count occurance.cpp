// Count Occurrences in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOccurrences(vector<int> &arr, int target)
    {
        vector<int> ans = {-1, -1};
        int lb = arr.size(), ub = arr.size();
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target)
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
        high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                ub = mid;
                low = mid + 1;
            }
        }

        if (lb != arr.size() && arr[lb] == target)
        {
            ans[0] = lb;
            ans[1] = lb;
        }
        if (ub != arr.size() && arr[ub] == target)
        {
            ans[1] = ub;
        }
        if (ans[0] == -1)
        {
            return 0;
        }
        else
        {
            return (ans[1] - ans[0] + 1);
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = {5, 7, 7, 8, 8, 8, 8, 10};

    cout << s.countOccurrences(arr, 8) << endl;
    return 0;
}
