// https://leetcode.com/problems/sum-of-square-numbers/description/
// 633 (Medium) Sum of square is a number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int maxEle = (int)pow(c, 0.5);

        int low = 0, high = maxEle;
        while (low <= high)
        {
            long long squareSum = low * low + high * high;
            if (squareSum == c)
            {
                return true;
            }
            else if (squareSum < c)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}