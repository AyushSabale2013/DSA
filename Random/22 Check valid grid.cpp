// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// 1391 (Medium) Check valid grid

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasValidPath(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Directions: Left, Right, Up, Down
        vector<vector<pair<int,int>>> dir = {
            {},
            {{0,-1},{0,1}},      // type 1
            {{-1,0},{1,0}},      // type 2
            {{0,-1},{1,0}},      // type 3
            {{0,1},{1,0}},       // type 4
            {{0,-1},{-1,0}},     // type 5
            {{0,1},{-1,0}}       // type 6
        };

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1)
                return true;

            for(auto [dx,dy] : dir[grid[x][y]])
            {
                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if(vis[nx][ny])
                    continue;

                // Check if neighbor connects back
                for(auto [bdx,bdy] : dir[grid[nx][ny]])
                {
                    if(nx + bdx == x && ny + bdy == y)
                    {
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
};



int main()
{

    return 0;
}