// https://leetcode.com/problems/isomorphic-strings/description/
// 205 (easy) - Check two strings are isomorphic or not

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int low = 0;
        int high = static_cast<int>(s.length()) - 1;
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        while (low <= high)
        {
            m1[s[low]] = t[low];
            m2[t[low]] = s[low];
            low++;
        }

        string t_copy = "";
        string s_copy = "";
        low = 0;

        while (low <= high)
        {
            t_copy += m1[s[low]];
            s_copy += m2[t[low]];

            low++;
        }

        if ((t_copy == t) && (s_copy == s))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s1 = "paper";
    string s2 = "title";
    Solution s;
    cout << s.isIsomorphic(s1, s2) << endl;

    return 0;
}
