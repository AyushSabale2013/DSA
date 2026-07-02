// Find Nth root of a number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long power(long long x, long long n)
    {
        long long ans = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans *= x;
            }

            x *= x;
            n /= 2;
        }

        return ans;
    }
    int NthRoot(int N, int M)
    {
        int low = 1, high = M;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (power(mid, N) == M)
            {
                return mid;
            }
            else if (power(mid, N) < M)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.NthRoot(3, 27) << endl;
    return 0;
}