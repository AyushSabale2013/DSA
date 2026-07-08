// https://leetcode.com/problems/maximum-number-of-balloons/
// 1189 (Easy) - Max number of balloons

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> mp;
        int ans = 0;
        for (auto ch : text)
        {
            mp[ch]++;
        }
        mp['l'] /= 2;
        mp['o'] /= 2;
        vector<pair<char, int>> balloon = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for (int i = 0; i < 5; i++)
        {
            balloon[i].second = mp[balloon[i].first];
        }
        ans = balloon[0].second;
        for (auto ele : balloon)
        {
            if (ele.second < ans)
            {
                ans = ele.second;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}