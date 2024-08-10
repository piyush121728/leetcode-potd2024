#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<vector<int>>> vis;
    int n, m;
    void dfs(int row, int col, int type, vector<string> &grid)
    {
        if (row < 0 || row >= n || col < 0 || col >= m || vis[row][col][type])
            return;

        vis[row][col][type] = 1;
        if (type == 0)
        {
            dfs(row - 1, col, 2, grid);
        }
        else if (type == 1)
        {
            dfs(row, col + 1, 3, grid);
        }
        else if (type == 2)
        {
            dfs(row + 1, col, 0, grid);
        }
        else if (type == 3)
        {
            dfs(row, col - 1, 1, grid);
        }

        if (grid[row][col] != '/')
        {
            dfs(row, col, type ^ 1, grid);
        }
        if (grid[row][col] != '\\')
        {
            dfs(row, col, type ^ 3, grid);
        }
    }
    int regionsBySlashes(vector<string> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        vis.resize(n, vector<vector<int>>(m, vector<int>(4, 0))); // vis vector
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                for (int type = 0; type < 3; type++)
                {
                    if (!vis[row][col][type])
                    {
                        dfs(row, col, type, grid);
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

// link : https://leetcode.com/problems/regions-cut-by-slashes/submissions/1350912945/?envType=daily-question&envId=2024-08-10