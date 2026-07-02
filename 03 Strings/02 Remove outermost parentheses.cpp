// https://leetcode.com/problems/remove-outermost-parentheses/
// 1021 (easy) - Remove outermost parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> st;
        string ans;
        ans.reserve(static_cast<int>(s.size())); // Avoid repeated reallocations

        for (char c : s)
        {
            if (c == '(')
            {
                if (!st.empty())
                    ans += c;

                st.push(c);
            }
            else
            {
                st.pop();

                if (!st.empty())
                    ans += c;
            }
        }

        return ans;
    }
};

int main()
{
    string par = "(()())(())(()(()))";
    Solution s;
    cout << s.removeOuterParentheses(par) << endl;

    return 0;
}