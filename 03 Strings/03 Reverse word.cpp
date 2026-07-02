// https://leetcode.com/problems/reverse-words-in-a-string/description/
// 151 (medium) - Reverse word in string

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void addWordToReversed(string &ans, stack<char> &st)
    {
        if (st.empty())
        {
            return;
        }
        int low = st.size();
        if (ans != "")
        {
            ans += " ";
        }

        while (low > 0)
        {
            ans += st.top();
            st.pop();

            low--;
        }
    }
    string reverseWords(string s)
    {
        int low = static_cast<int>(s.length()) - 1;
        string ans = "";
        stack<char> st;

        while (low >= 0)
        {
            if (s[low] == ' ')
            {
                addWordToReversed(ans, st);
            }
            else
            {
                st.push(s[low]);
            }

            low--;
        }
        addWordToReversed(ans, st);
        return ans;
    }
};

int main()
{
    string sentence = "a good   example";
    Solution s;
    cout << s.reverseWords(sentence) << endl;

    return 0;
}