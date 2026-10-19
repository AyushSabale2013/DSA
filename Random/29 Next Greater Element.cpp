

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int cur : nums2)
        {
            while (!st.empty() && st.top() < cur)
            {
                nextGreater[st.top()] = cur;
                st.pop();
            }
            st.push(cur);
        }
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int x : nums1)
        {
            auto it = nextGreater.find(x);
            ans.push_back(it != nextGreater.end() ? it->second : -1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for (int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}