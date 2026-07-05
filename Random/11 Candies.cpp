// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// 1431 (Easy) - Kids with candies

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max_candies = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size());

        int low = 0;
        for (int candy : candies)
        {
            if (candy + extraCandies >= max_candies)
            {
                ans[low] = true;
            }
            else
            {
                ans[low] = false;
            }
            low++;
        }

        return ans;
    }
};
int main()
{

    return 0;
}