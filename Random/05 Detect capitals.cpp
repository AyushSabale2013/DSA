// https://leetcode.com/problems/detect-capital/
// 520 (Easy) - Detect capital use

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        bool allUpper = true;
        bool allLower = true;
        bool firstUpperRestLower = word[0] >= 'A' && word[0] <= 'Z';

        for (int i = 0; i < word.size(); i++)
        {
            if (!(word[i] >= 'A' && word[i] <= 'Z'))
                allUpper = false;

            if (!(word[i] >= 'a' && word[i] <= 'z'))
                allLower = false;

            if (i > 0 && !(word[i] >= 'a' && word[i] <= 'z'))
                firstUpperRestLower = false;
        }

        return allUpper || allLower || firstUpperRestLower;
    }
};
int main()
{
    Solution s;
    string word = "USA";
    cout << s.detectCapitalUse(word) << endl;

    return 0;
}
