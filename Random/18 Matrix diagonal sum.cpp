// https://leetcode.com/problems/matrix-diagonal-sum/description/
// 1572 (Easy) - MAtrix diagonal sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int sizeOfMat = static_cast<int>(mat.size());
        int sum = 0;

        for (int i = 0; i < sizeOfMat; i++)
        {
            sum += mat[i][i];
            sum += mat[i][sizeOfMat - (i + 1)];
        }
        if (sizeOfMat % 2 != 0)
        {
            sum -= mat[sizeOfMat / 2][sizeOfMat / 2];
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    cout << s.diagonalSum(mat) << endl;

    return 0;
}