// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// 1391 (Medium) Check valid grid

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<char, char> openings(int n)
    {
        pair<char, char> ans;
        switch (n)
        {
        case 1:
            ans.first = 'L';
            ans.second = 'R';
            break;
        case 2:
            ans.first = 'U';
            ans.second = 'B';
            break;
        case 3:
            ans.first = 'L';
            ans.second = 'B';
            break;
        case 4:
            ans.first = 'R';
            ans.second = 'B';
            break;
        case 5:
            ans.first = 'L';
            ans.second = 'U';
            break;
        case 6:
            ans.first = 'R';
            ans.second = 'U';
            break;

        default:
            ans.first = 'C';
            ans.second = 'C';
            break;
        }

        return ans;
    }

    bool isConnected(pair<int, int> &prev, pair<int, int> &curr)
    {
        
        return true;
    }

    pair<int, int> next(pair<int, int> &prev, pair<int, int> &curr)
    {
        return curr;
    }
    pair<int, int> nextForHead(pair<int, int> &curr)
    {
        return curr;
    }

    bool hasValidPath(vector<vector<int>> &grid)
    {
        // m rows and n cols
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        if (n == 1 && m == 1)
        {
            return true;
        }
        if (grid[0][0] == 5)
        {
            return false;
        }
        pair<int, int> curr = {0, 0};
        pair<int, int> prev = {0, 0};
        if (grid[0][0] == 4)
        {

            // Speacial case
        }

        // initiate :
        pair<int, int> newCurr = nextForHead(curr);
        if (isConnected(curr, newCurr))
        {
            curr = newCurr;
        }
        else
        {
            return false;
        }

        // while loop
        while (true)
        {
            if (curr.first == (m - 1) && curr.second == (n - 1))
            {
                return true;
            }

            newCurr = next(prev, curr);
            if (isConnected(curr, newCurr))
            {
                prev = curr;
                curr = newCurr;
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{

    return 0;
}