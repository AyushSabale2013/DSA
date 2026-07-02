// https://leetcode.com/problems/kth-missing-positive-number/
// 1539 Missing positive number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int index = 0;
        vector<int> missing(0);

        while (low <= high)
        {
            if (arr[index] == low)
            {
                index++;
            }
            else
            {
                missing.push_back(low);
            }
            low++;
        }

        int ans;
        int miss_size = static_cast<int>(missing.size());
        if (miss_size == 0)
        {
            ans = high + k;
            return ans;
        }

        if (k <= miss_size)
        {
            ans = missing[k - 1];
            return ans;
        }

        ans = arr[static_cast<int>(arr.size()) - 1] + (k - miss_size);
        return ans;
    }
};

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9};
    Solution s;
    cout << s.findKthPositive(arr, 9)
         << endl;

    return 0;
}