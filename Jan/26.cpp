#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1000000007;
    int dfs(int m, int n, int moves, int r, int c, vector<vector<vector<int>>> &dp)
    {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return 1;
        if (moves == 0)
            return 0;
        if (dp[moves][r][c] != -1)
            return dp[moves][r][c] % mod;

        int res = 0;
        res = (res + dfs(m, n, moves - 1, r, c - 1, dp)) % mod;
        res = (res + dfs(m, n, moves - 1, r + 1, c, dp)) % mod;
        res = (res + dfs(m, n, moves - 1, r - 1, c, dp)) % mod;
        res = (res + dfs(m, n, moves - 1, r, c + 1, dp)) % mod;

        return dp[moves][r][c] = res % mod;
    }

public:
    int findPaths(int m, int n, int N, int i, int j)
    {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(m, n, N, i, j, dp);
    }
};

// link : https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26