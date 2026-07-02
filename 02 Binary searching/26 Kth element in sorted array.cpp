// https://takeuforward.org/plus/dsa/problems/kth-element-of-2-sorted-arrays?source=strivers-a2z-dsa-track

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
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        vector<int> merged = mergeArray(a , b);

        return merged[k-1];
    }
};

int main()
{

    return 0;
}