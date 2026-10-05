// https://leetcode.com/problems/score-of-parentheses/submissions/2162784167/?envType=daily-question&envId=2026-10-05
// 856 (Medium) Score Of parenthesis

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        int score = 0;
        st.push(0);

        for (char ch : s)
        {
            if (ch == '(')
            {
                st.push(0);
            }
            else
            {
                int inner = st.top();
                st.pop();

                if (inner == 0)
                {
                    score = 1;
                }
                else
                {
                    score = inner * 2;
                }

                st.top() += score;
            }
        }

        return st.top();
    }
};

int main()
{
    Solution s;
    cout << s.scoreOfParentheses("((()()))") << endl;

    return 0;
}