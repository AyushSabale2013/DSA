// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// 1614 (Easy) - Maximum nesting depth of parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int total = 0;
        int maxd = 0;
        for (char ele : s)
        {
            if (ele == '(')
            {
                total++;
            }
            else if (ele == ')')
            {
                total--;
            }
            if (total > maxd)
            {
                maxd = total;
            }
                }

        return maxd;
    }
};

int main()
{
    Solution s;
    string name = "(1+(2*3)+((8)/4))+1";

    cout << s.maxDepth(name) << endl;

    return 0;
}