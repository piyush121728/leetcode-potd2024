#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    int ninjaTraining(int days, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        // base case
        if (days == 0)
        {
            int mini = 1e8;
            for (int tasks = 0; tasks < m; tasks++)
            {
                if (tasks != lastTask)
                {
                    mini = min(mini, points[0][tasks]);
                }
            }
            return mini;
        }

        if (dp[days][lastTask] != -1)
        {
            return dp[days][lastTask];
        }

        // recursive call
        int mini = 1e8;
        for (int tasks = 0; tasks < m; tasks++)
        {
            if (tasks != lastTask)
            {
                int point = points[days][tasks] + ninjaTraining(days - 1, tasks, points, dp);
                mini = min(mini, point);
            }
        }

        return dp[days][lastTask] = mini;
    }

    int minFallingPathSum(vector<vector<int>> &points)
    {
        n = points.size();
        m = points[0].size();
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        return ninjaTraining(n - 1, m, points, dp); //(day,lastTask,points)
    }
};

// link : https://leetcode.com/problems/minimum-falling-path-sum-ii/solutions/?envType=daily-question&envId=2024-04-26