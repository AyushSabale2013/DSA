// https://leetcode.com/problems/remove-duplicate-letters/description/
// 316 (Medium) - Remove duplicate letters

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> freq;
        unordered_map<char, bool> visited;

        // Count frequency
        for (char ch : s)
        {
            freq[ch]++;
        }

        string ans;

        for (char ch : s)
        {
            // Current character is being processed
            freq[ch]--;

            // Already in answer
            if (visited[ch])
                continue;

            // Remove larger characters that will appear again
            while (!ans.empty() &&
                   ans.back() > ch &&
                   freq[ans.back()] > 0)
            {
                visited[ans.back()] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch] = true;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    string name = "cbacdcbc";
    cout << s.removeDuplicateLetters(name) << endl;

    return 0;
}
