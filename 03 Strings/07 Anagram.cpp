

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        int low = 0;
        int high = static_cast<int>(s.length()) - 1;
        while (low <= high)
        {
            m1[s[low]]++;
            m2[t[low]]++;

            low++;
        }
        low = 0;
        while (low <= high)
        {
            if (m1[s[low]] != m2[s[low]])
            {
                return false;
            }
            low++;
        }

        return true;
    }
};

int main()
{
    Solution s;
    string original = "cat";
    string goal = "rat";
    cout << s.isAnagram(original, goal) << endl;

    return 0;
}