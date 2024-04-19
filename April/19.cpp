#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();

        visited[i][j] = 1;

        // now, we will traverse its negihbours in all 4 direction
        // shortcut to traverse in all direction
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        for (int d = 0; d <= 3; d++)
        {
            int nr = i + delr[d];
            int nc = j + delc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == '1')
            {
                dfs(nr, nc, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int islands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {

                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};

// link :    https://leetcode.com/problems/number-of-islands/submissions/1236553582/?envType=daily-question&envId=2024-04-19