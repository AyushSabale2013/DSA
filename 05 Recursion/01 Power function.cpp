// https://leetcode.com/problems/powx-n/description/
// 50 (Medium) Find nth power of x

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double power(double x, long long n)
    {
        if (n == 0)
            return 1;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return x * half * half;
    }
    double myPow(double x, int n)
    {
        long long N = n;

        if (N < 0)
            return 1.0 / power(x, -N);

        return power(x, N);
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, -15) << endl;

    return 0;
}