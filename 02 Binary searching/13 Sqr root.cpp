// Finding closest sqr root using binary search

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int floorSqrt(int n)
    {
        int low = 1, high = n;
        int ans = 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid * mid <= n)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.floorSqrt(28) << endl;
    return 0;
}