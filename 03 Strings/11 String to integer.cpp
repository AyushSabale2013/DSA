// https://leetcode.com/problems/string-to-integer-atoi/description/
// 8 (Medium) - Conversion of String to Integer

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInt(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    int character_to_int(char ch)
    {
        return ch - '0';
    }

    void updateAns(int &ans, char ch, bool &integerOverflowHappened, bool ispositive)
    {
        int digit = character_to_int(ch);

        if (ispositive)
        {
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7))
            {
                integerOverflowHappened = true;
                return;
            }

            ans = ans * 10 + digit;
        }
        else
        {
            if (ans < INT_MIN / 10 ||
                (ans == INT_MIN / 10 && digit > 8))
            {
                integerOverflowHappened = true;
                return;
            }

            ans = ans * 10 - digit;
        }
    }

    int myAtoi(string s)
    {
        int low = 0;
        int high = static_cast<int>(s.length());

        bool ispositive = true;
        bool signAppearedBefore = false;
        bool numberCountingStarted = false;
        bool numberAppeared = false;
        bool integerOverflowHappened = false;

        int ans = 0;

        while (low < high)
        {
            if (!numberAppeared && s[low] == ' ')
            {
                low++;
                continue;
            }
            else if (!numberAppeared && s[low] == '-')
            {
                numberAppeared = true;

                if (signAppearedBefore)
                    break;

                signAppearedBefore = true;
                ispositive = false;
            }
            else if (!numberAppeared && s[low] == '+')
            {
                numberAppeared = true;

                if (signAppearedBefore)
                    break;

                signAppearedBefore = true;
                ispositive = true;
            }
            else if (!numberCountingStarted && s[low] == '0')
            {
                numberAppeared = true;
                low++;
                continue;
            }
            else if (checkInt(s[low]))
            {
                numberAppeared = true;
                numberCountingStarted = true;

                updateAns(ans, s[low], integerOverflowHappened, ispositive);

                if (integerOverflowHappened)
                {
                    return ispositive ? INT_MAX : INT_MIN;
                }
            }
            else
            {
                break;
            }

            low++;
        }

        return ans;
    }
};




int main()
{
    Solution s;
    string Number = "35";

    cout << s.myAtoi(Number) << endl;

    return 0;
}