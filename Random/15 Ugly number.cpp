// https://leetcode.com/problems/ugly-number/
// 263 (Easy) - Ugly number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }

        while (n % 30 == 0)
        {
            n /= 30;
        }
        while (n % 5 == 0)
        {
            n /= 5;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        while (n % 2 == 0)
        {
            n /= 2;
        }
        if (n == 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}