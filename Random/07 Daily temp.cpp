// https://leetcode.com/problems/daily-temperatures/description/
// 739 (Medium) - Daily temperature

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(static_cast<int>(temperatures.size()));
        stack<int> st;
        int low = 0, high = static_cast<int>(temperatures.size());

        while (low < high)
        {
            while (!st.empty() && temperatures[low] > temperatures[st.top()])
            {
                ans[st.top()] = low - st.top();
                st.pop();
            }

            st.push(low);
            low++;
        }

        return ans;
    }
};

void printVector(vector<int> &ans)
{
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{

    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = s.dailyTemperatures(temperatures);

    printVector(ans);

    return 0;
}