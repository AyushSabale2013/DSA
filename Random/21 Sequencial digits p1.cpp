// https://leetcode.com/problems/sequential-digits/description/
// 1291 (Medium) Sequencial digits

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrayToNum(vector<int> &arr)
    {
        int num = 0;
        for (int x : arr)
            num = num * 10 + x;
        return num;
    }

    void nextSequential(vector<int> &arr)
    {
        int n = arr.size();

        // Example: 789 -> 1234
        if (arr.back() == 9)
        {
            arr.resize(n + 1);
            arr[0] = 1;
            for (int i = 1; i <= n; i++)
                arr[i] = arr[i - 1] + 1;
        }
        else
        {
            // Example: 234 -> 345
            for (int &x : arr)
                x++;
        }
    }

    int digits(int x)
    {
        int cnt = 0;
        while (x)
        {
            cnt++;
            x /= 10;
        }
        return cnt;
    }

    vector<int> sequentialDigits(int low, int high)
    {
        int d = digits(low);

        // Build first sequential number of d digits
        vector<int> cur(d);
        for (int i = 0; i < d; i++)
            cur[i] = i + 1;

        // Shift until >= low
        while (arrayToNum(cur) < low)
            nextSequential(cur);

        vector<int> ans;

        while (true)
        {
            int num = arrayToNum(cur);

            if (num > high)
                break;

            if (num >= low)
                ans.push_back(num);

            nextSequential(cur);
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