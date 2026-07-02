// https://leetcode.com/problems/rotate-string/description/
// 796 (Easy) - Rotate String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string rotateString(string s, int k)
    {
        string rotatedpPart = "";
        int low = 0;
        int high = static_cast<int>(s.length()) - 1;
        while (low < k)
        {
            rotatedpPart += s[low];
            low++;
        }
        low = 0;
        while (k <= high)
        {
            s[low] = s[k];

            low++;
            k++;
        }
        k = 0;
        while (low <= high)
        {
            s[low] = rotatedpPart[k];
            k++;
            low++;
        }
        return s;
    }

    
    bool rotateString(string s, string goal)
    {
        int maxRotations = static_cast<int>(s.length());
        int k = 0;

        while (maxRotations > 0)
        {
            if (rotateString(s, k) == goal)
            {
                return true;
            }
            k++;
            maxRotations--;
        }
        return false;
    }
};

int main()
{
    Solution s;
    string original = "abcde";
    string goal = "cdeab";
    cout << s.rotateString(original, goal) << endl;

    return 0;
}