// https://leetcode.com/problems/roman-to-integer/description/
// 13 (Easy) - Roman to Integer Conversion

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int value(char ch)
    {

        switch (ch)
        {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;

        default:
            return 0;
            break;
        }
    }
    int romanToInt(string s)
    {

        int low = 0, high = static_cast<int>(s.length()) - 1;
        int ans = 0;
        while (low <= high)
        {

            if (low < high && (value(s[low]) < value(s[low + 1])))
            {

                ans += value(s[low + 1]) - value(s[low]);
                low++;
            }
            else
            {
                ans += value(s[low]);
            }
            low++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string Number = "XXIV";

    cout << s.romanToInt(Number) << endl;

    return 0;
}

// I   ->  1
// V   ->  5
// X   ->  10
// L   ->  50
// C   ->  100
// D   ->  500
// M   ->  1000