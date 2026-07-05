// https://leetcode.com/problems/happy-number/description/
// 202 (Easy) - Happy number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> s;
        while (n != 1)
        {
            if (s.count(n))
                return false;
            s.insert(n);

            int sum = 0;
            while (n)
            {
                int rem = n % 10;
                sum += rem * rem;
                n = n / 10;
            }
            n = sum;
        }
        return true;
    }
};

int main()
{

    Solution s;
    cout << s.isHappy(7) << endl;
    return 0;
}