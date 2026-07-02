// https://leetcode.com/problems/sort-characters-by-frequency/
// 451 (medium) - Sort Characters by frequency

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;
        multimap<int, char> inverted_mp;
        for (char ele : s)
        {
            mp[ele]++;
        }

        for (auto it : mp)
        {
            inverted_mp.emplace(it.second, it.first);
        }
        s = "";
        for (auto it : inverted_mp)
        {
            int total = it.first;
            while (total > 0)
            {
                s += it.second;
                total--;
            }
        }

        reverse(s.begin(), s.end());

        return s;
    }
};

int main()
{
    Solution s;
    string name = "AAyushhh";

    cout << s.frequencySort(name) << endl;

    return 0;
}