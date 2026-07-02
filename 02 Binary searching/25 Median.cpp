// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// 4 (hard) - Median of two sorted arrays

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> mergeArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0, j = 0, k = 0;

        vector<int> merged(n1 + n2);

        while (i < n1 && j < n2)
        {
            if (nums1[i] <= nums2[j])
                merged[k++] = nums1[i++];
            else
                merged[k++] = nums2[j++];
        }

        while (i < n1)
            merged[k++] = nums1[i++];

        while (j < n2)
            merged[k++] = nums2[j++];

        return merged;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged = mergeArray(nums1, nums2);

        int n = merged.size();

        if (n % 2 == 1)
            return merged[n / 2];

        return (merged[n / 2] + merged[n / 2 - 1]) / 2.0;
    }
};

int main()
{
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 4};
    Solution s;
    cout << s.findMedianSortedArrays(arr1, arr2)
         << endl;

    // for (auto ele : s.mergeArray(arr1, arr2))
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;

    return 0;
}