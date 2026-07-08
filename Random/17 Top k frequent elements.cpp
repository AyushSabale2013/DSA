// https://leetcode.com/problems/top-k-frequent-elements/description/
// 347 (Medium) - Top Frequent k ele

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans(k);
        for (auto num : nums)
        {
            mp[num]++;
        }
        vector<pair<int, int>> mapping(mp.size());
        int low = 0;
        for (auto it : mp)
        {
            mapping[low] = it;
            low++;
        }

        auto cmp = [](pair<int, int> &a, pair<int, int> &b)
        {
            if (a.second > b.second)
            {
                return true;
            }
            return false;
        };
        sort(mapping.begin(), mapping.end(), cmp);
        for (int i = 0; i < k; i++)
        {
            ans[i] = mapping[i].first;
        }

        return ans;
    }
};

int main()
{

    return 0;
}