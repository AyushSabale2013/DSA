// My first Crazy Question
// https://leetcode.com/problems/koko-eating-bananas/
// 875 KOKO eating bananas

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAns(vector<int> &piles, int speed, int h)
    {
        int low = 0;
        bool ans = true;
        while (low < static_cast<int>(piles.size()))
        {
            if (piles[low] <= speed)
            {
                h--;
            }
            else if (piles[low] > speed)
            {
                int required_time = (piles[low] + speed - 1) / speed;

                h = h - required_time;
            }
            if (h < 0)
            {
                ans = false;
                break;
            }
            low++;
        }

        return ans;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {

        int mx = *max_element(piles.begin(), piles.end());
        int low = 1, high = mx;
        int ans = mx;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (checkAns(piles, mid, h))
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
    Solution s;
    vector<int> arr = {3, 6, 7, 11};

    cout << s.minEatingSpeed(arr, 8) << endl;
    return 0;
}