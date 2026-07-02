// https://leetcode.com/problems/longest-palindromic-substring/description/
// 5 (Medium) - Find longest palindromic substring
// Following solution is O(n^2) 
// we can implement better solution for this in O(n) using manacher algo
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxPalindromeFromCenter(vector<char> &demo, int center)
    {
        vector<int> ans(2);
        int left = center, right = center;
        int sizeOfDemo = static_cast<int>(demo.size());
        while (left >= 0 && right < sizeOfDemo)
        {
            if (demo[left] != demo[right])
            {
                break;
            }
            left--;
            right++;
        }
        left++;
        right--;
        ans[0] = left;
        ans[1] = right;
        // both left ans right are included

        return ans;
    }

    string longestPalindrome(string s)
    {
        int sizeOfDemo = 2 * s.length() + 1;
        vector<char> demo(sizeOfDemo);
        int low = 0;
        string ans = "";

        // Converting string into expandable vector
        while (low < sizeOfDemo)
        {
            if (low % 2 == 0)
            {
                demo[low] = ' ';
            }
            else
            {
                demo[low] = s[(low - 1) / 2];
            }
            low++;
        }

        // Expanding each center
        int maxSizeOfPalindrome = 0;
        int left = 0, right = 0;
        low = 0;
        while (low < sizeOfDemo)
        {
            vector<int> rangeOfDemo = maxPalindromeFromCenter(demo, low);
            if (((rangeOfDemo[1] - rangeOfDemo[0]) + 1) > maxSizeOfPalindrome)
            {
                maxSizeOfPalindrome = (rangeOfDemo[1] - rangeOfDemo[0]) + 1;
                left = rangeOfDemo[0];
                right = rangeOfDemo[1];
            }
            low++;
        }

        while (left <= right)
        {
            if (demo[left] == ' ')
            {
                left++;
                continue;
            }
            ans += demo[left];
            left++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    string original = "";

    cout << s.longestPalindrome(original) << endl;

    return 0;
}

