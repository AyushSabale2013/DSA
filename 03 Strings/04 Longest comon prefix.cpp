// https://leetcode.com/problems/longest-common-prefix/description/
// 14 (easy) - Longest Common Prefix

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findmin(vector<string> &strs)
    {
        int min = static_cast<int>(strs[0].length());
        for (string &str : strs)
        {
            if (str.length() < min)
            {
                min = str.length();
            }
        }
        return min;
    }

    bool checkAns(vector<string> &strs, int i)
    {
        char letter = strs[0][i];
        for (string &str : strs)
        {
            if (str[i] != letter)
            {
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        int minsize = findmin(strs);
        int ans = -1;
        string prefix = "";
        for (int i = 0; i < minsize; i++)
        {
            if (checkAns(strs, i))
            {
                ans = i;
            }
            else
            {
                break;
            }
        }
        int low = 0;
        while (ans >= 0)
        {
            prefix += strs[0][low];
            low++;
            ans--;
        }

        return prefix;
    }
};

int main()
{
    vector<string> strs = {"dog", "racecar", "car"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}