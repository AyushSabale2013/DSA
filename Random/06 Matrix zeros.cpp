// https://leetcode.com/problems/set-matrix-zeroes/
// 73 (Medium) - Set matrix zeros

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<bool, bool> checkSpeacialCase(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        pair<bool, bool> ans = {false, false};
        while (i < m)
        {
            if (matrix[i][0] == 0)
            {
                ans.first = true;
                break;
            }
            i++;
        }
        while (j < n)
        {
            if (matrix[0][j] == 0)
            {
                ans.second = true;
                break;
            }
            j++;
        }
        return ans;
    }

    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        pair specialCaseExists = checkSpeacialCase(matrix);
        int i = 0;

        while (i < m)
        {
            int j = 0;
            while (j < n)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
                j++;
            }
            i++;
        }


        i = 1;
        while (i < m)
        {
            int j = 1;
            while (j < n)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
                j++;
            }
            i++;
        }

        if (specialCaseExists.first)
        {
            i = 0;
            while (i < m)
            {
                matrix[i][0] = 0;
                i++;
            }
        }

        if (specialCaseExists.second)
        {
            i = 0;
            while (i < n)
            {
                matrix[0][i] = 0;
                i++;
            }
        }
    }
};

int main()
{

    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    s.setZeroes(matrix);

    return 0;
}
