// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// Q 1482

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAns(vector<int> &bloomDay, int m, int k, int days)
    {
        int flowers = 0;

        for (int bloom : bloomDay)
        {
            if (bloom <= days)
            {
                flowers++;

                if (flowers == k)
                {
                    m--;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }

        return m <= 0;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int low = 1, high = mx;
        int ans = mx;
        if (static_cast<long long>(bloomDay.size()) / k < m)
        {
            return -1;
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (checkAns(bloomDay, m, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            // O(log(max_ele))
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 10, 3, 10, 2};
    Solution s;
    cout << s.minDays(arr, 3, 1)
         << endl;

    return 0;
}