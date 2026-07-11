// https://leetcode.com/problemset/
// 1922 (Medium) Count good numbers

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long power(double x, long long n)
    {
        if (n == 0)
            return 1;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return x * half * half;
    }
    int countGoodNumbers(long long n)
    {
        long long ans = 0;
        if (n % 2 == 0)
        {
            ans = power(5, n / 2) * power(4, n / 2);
        }
        ans = power(5, (n - 1) / 2) * power(4, (n - 1) / 2) * 5;

        if (ans > INT_MAX)
        {
            return ans % (1000000007);
        }
        return ans;
    }
};

int main()
{

    return 0;
}