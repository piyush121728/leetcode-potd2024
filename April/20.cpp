#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int r1, c1, r2, c2, n, m;
    vector<vector<int>> visited;
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        visited[i][j] = 1;
        r1 = min(r1, i);
        c1 = min(c1, j);
        r2 = max(r2, i);
        c2 = max(c2, j);

        // now, we will traverse its negihbours in all 4 direction
        // shortcut to traverse in all direction
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        for (int d = 0; d <= 3; d++)
        {
            int nr = i + delr[d];
            int nc = j + delc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr, nc, grid);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &grid)
    {
        visited.clear();
        n = grid.size();
        m = grid[0].size();
        visited.resize(n, vector<int>(m, 0));
        vector<vector<int>> res;

        int islands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    r1 = INT_MAX, c1 = INT_MAX, r2 = INT_MIN, c2 = INT_MIN;
                    dfs(i, j, grid);
                    res.push_back({r1, c1, r2, c2});
                }
            }
        }
        return res;
    }
};

// link : https://leetcode.com/problems/find-all-groups-of-farmland/?envType=daily-question&envId=2024-04-20