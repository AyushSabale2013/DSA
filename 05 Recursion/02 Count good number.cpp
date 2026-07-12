// https://leetcode.com/problemset/
// 1922 (Medium) Count good numbers

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long power(int x, long long n)
    {
        if (n == 0)
            return 1;

        long long half = power(x, n / 2);
        half = half % 1000000007;

        if (n % 2 == 0)
        {
            long long ans = (1LL * half * half) % 1000000007;
            return ans;
        }
        long long ans = (1LL * half * half * x) % 1000000007;
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        long long ans = 0;
        if (n % 2 == 0)
        {
            ans = (1LL * power(5, n / 2) * power(4, n / 2)) % 1000000007;
            return ans;
        }

        ans = (5 * power(5, (n - 1) / 2) * power(4, (n - 1) / 2)) % 1000000007;
        return ans;
    }
};

int main()
{

    return 0;
}