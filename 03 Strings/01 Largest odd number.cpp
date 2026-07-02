// https://leetcode.com/problems/largest-odd-number-in-string/description/
//  1903 (Easy) - Find largest odd number in given string

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (num[i] % 2 == 1)
            {
                ans += num.substr(0, i + 1);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    string num = "35427";
    Solution s;
    cout << s.largestOddNumber(num) << endl;

    return 0;
}