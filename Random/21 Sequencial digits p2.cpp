// https://leetcode.com/problems/sequential-digits/description/
// 1291 (Medium) Sequencial digits

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> returnALLSeq()
    {
        vector<int> seq;

        for (int len = 2; len <= 9; len++)
        {
            for (int start = 1; start <= 10 - len; start++)
            {
                int num = 0;

                for (int d = 0; d < len; d++)
                {
                    num = num * 10 + (start + d);
                }

                seq.push_back(num);
            }
        }
        return seq;
    }

    pair<int, int> range(int low, int high)
    {
        vector<int> allSeq = returnALLSeq();
        pair<int, int> ans = {allSeq.size(), -1};
        int counter = 0;
        for (auto ele : allSeq)
        {
            if (ele >= low)
            {
                ans.first = counter;
                break;
            }
            counter++;
        }
        counter = 0;
        for (auto ele : allSeq)
        {
            if (ele <= high)
            {
                ans.second = counter;
            }
            else
            {
                break;
            }
            counter++;
        }

        return ans;
    }
    vector<int> sequentialDigits(int low, int high)
    {
        pair<int, int> RangeLimit = range(low, high);
        vector<int> allSeq = returnALLSeq();
        vector<int> emptyarr;
        if (RangeLimit.first > RangeLimit.second)
        {
            return emptyarr;
        }

        vector<int> ans(RangeLimit.second - RangeLimit.first + 1);
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = allSeq[i + RangeLimit.first];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = s.sequentialDigits(1000, 30000);

    return 0;
}