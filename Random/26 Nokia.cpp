// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
// 3016 (Medium) - Nokia keypad

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<pair<char, int>> freq(26);

        for (int i = 0; i < 26; i++)
            freq[i].first = 'a' + i;

        for (char ch : word)
        {
            freq[ch - 'a'].second++;
        }

        sort(freq.begin(), freq.end(), [](auto &a, auto &b)
             { return a.second > b.second; });

        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i].second == 0)
                break;

            int pushes = i / 8 + 1;
            ans += pushes * freq[i].second;
        }

        return ans;
    }
};

//
int main()
{
    Solution s;
    string word = "abzaqsqcyrbzsrvamylmyxdjl";
    cout << s.minimumPushes(word) << endl;

    return 0;
}