// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
// 1781 (Medium) - Beauty of all substrings

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int sum = 0;

        for (int start = 0; start < n; start++)
        {
            unordered_map<char, int> mp;

            for (int end = start; end < n; end++)
            {
                mp[s[end]]++;

                int mx = INT_MIN;
                int mn = INT_MAX;

                for (auto &it : mp)
                {
                    mx = max(mx, it.second);
                    mn = min(mn, it.second);
                }

                sum += (mx - mn);
            }
        }

        return sum;
    }
};

int main()
{
    Solution s;
    string original = "aaaaaaa";
    cout << s.beautySum(original) << endl;

    return 0;
}