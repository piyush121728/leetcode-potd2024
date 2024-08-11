#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();

        visited[i][j] = 1;

        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,1,0,-1};
        for(int d = 0; d <= 3; d++)
        {
            int nr = i +delr[d];
            int nc = j +delc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr,nc,grid,visited);
            }
        }
    }

    int numIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int islands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int il = numIslands(grid);
        if(il==0 || il>1){
            return 0;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    int il = numIslands(grid);
                    grid[i][j]=1;
                    if(il==0 || il>1){
                        return 1;
                    }
                }
            }
        }

        return 2;
    }
};

// link : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/?envType=daily-question&envId=2024-08-11