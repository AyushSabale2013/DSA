// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/
// 1160 (Easy) Find words that can be formed by given chars
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int total = 0;
        unordered_map<char, int> mp;
        for (char ch : chars)
        {
            mp[ch]++;
        }
        for (auto word : words)
        {
            unordered_map<char, int> temp = mp;
            bool possible = true;
            for (auto ch : word)
            {
                temp[ch]--;
                if (temp[ch] < 0)
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                total += word.length();
            }
        }

        return total;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"cat", "bt", "hat", "tree"};
    cout << s.countCharacters(words, "atach") << endl;

    return 0;
}