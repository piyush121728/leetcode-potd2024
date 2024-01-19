#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    vector<vector<int>> dp;
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int mini = 1e8;

        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int dl = 1e8, dr = 1e8;
                if (j > 0)
                {
                    dl = dp[i + 1][j - 1] + matrix[i][j];
                }
                if (j < n - 1)
                {
                    dr = dp[i + 1][j + 1] + matrix[i][j];
                }
                int down = dp[i + 1][j] + matrix[i][j];
                dp[i][j] = min({dl, down, dr});
            }
        }

        for (int j = 0; j < n; j++)
        {
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
};

// link : https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19