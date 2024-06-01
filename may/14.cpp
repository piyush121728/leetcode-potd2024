#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int delrow[4] = {1, -1, 0, 0};
    int delcol[4] = {0, 0, -1, 1};
    int n, m;

    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        int curr = grid[r][c];
        grid[r][c] = 0;
        int maxGold = curr;

        for (int i = 0; i < 4; i++)
        {
            int newr = r + delrow[i];
            int newc = c + delcol[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] != 0)
            {

                maxGold = max(maxGold, curr + dfs(grid, newr, newc));
            }
        }

        grid[r][c] = curr;
        return maxGold;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }

        return res;
    }
};

// link : https://leetcode.com/problems/path-with-maximum-gold/