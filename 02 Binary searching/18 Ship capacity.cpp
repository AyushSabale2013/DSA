// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// 1011 - Minimum capacity to ship to ship all packages in 'D' Days

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAns(vector<int> &weights, int days, int capacity)
    {
        int total = 0;
        int low = 0;
        while (low < static_cast<int>(weights.size()))
        {
            total += weights[low];
            if (total > capacity)
            {

                days--;
                total = 0;
            }
            else
            {
                low++;
            }
            if (days <= 0)
            {
                return false;
            }
        }
        return true;
    }
    int total(vector<int> &weights)
    {
        int total = 0;
        for (int weight : weights)
        {
            total += weight;
        }
        return total;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = 1, high = total(weights);
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (checkAns(weights, days, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution s;
    cout << s.checkAns(arr, 5, 10)
         << endl;

    return 0;
}