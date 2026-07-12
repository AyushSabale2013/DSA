// https://leetcode.com/problems/find-lucky-integer-in-an-array/
// 1394 (Easy) Finding lucky number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (int ele : arr)
        {
            mp[ele]++;
        }
        int ans = -1;
        for (auto it : mp)
        {
            if (it.first == it.second && it.first > ans)
            {
                ans = it.first;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}