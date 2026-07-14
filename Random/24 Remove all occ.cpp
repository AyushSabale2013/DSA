// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
// 1910 (Medium) Remove all occurances of substring

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<bool, int> findOccurance(string &s, string &part)
    {
        int sLength = s.length();
        int pLength = part.length();

        if (pLength == 0)
            return {true, 0};

        int low = 0;
        pair<bool, int> ans = {false, -1};

        int start = -1;
        int partC = 0;
        bool searchStarted = false;

        while (low < sLength)
        {
            if (searchStarted)
            {
                if (s[low] == part[partC])
                {
                    low++;
                    partC++;

                    // Match completed
                    if (partC == pLength)
                    {
                        ans.first = true;
                        ans.second = start;
                        return ans;
                    }
                }
                else
                {
                    searchStarted = false;
                    low = start + 1;
                    partC = 0;
                }
            }
            else
            {
                if (s[low] == part[0])
                {
                    start = low;
                    searchStarted = true;
                    partC = 1;
                    low++;

                    // Handles pattern of length 1
                    if (partC == pLength)
                    {
                        ans.first = true;
                        ans.second = start;
                        return ans;
                    }
                }
                else
                {
                    low++;
                }
            }
        }

        return ans;
    }

    string removeOccurrences(string s, string part)
    {
        pair<bool, int> aux = findOccurance(s, part);
        int lengthPart = part.length();

        // if not found then return s (base condtn)
        if (!aux.first)
        {
            return s;
        }

        // if found then remove part
        s.erase(aux.second, lengthPart);

        // call functions again and save in ans
        string ans = removeOccurrences(s, part);

        // return ans
        return ans;
    }
};

int main()
{
    Solution s;
    string sample = "daabcbaabcbc";
    string part = "abc";
    pair<bool, int> ans = s.findOccurance(sample, part);
    cout << ans.first << " " << ans.second << endl;
    cout << s.removeOccurrences(sample, part) << endl;

    return 0;
}