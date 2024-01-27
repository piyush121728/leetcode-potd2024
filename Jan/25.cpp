#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i == -1 || j == -1)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int match = 0;

        if (s[i] == t[j])
        {
            match = 1 + rec(i - 1, j - 1, s, t, dp);
        }

        int notMatch = max(rec(i - 1, j, s, t, dp), rec(i, j - 1, s, t, dp));

        return dp[i][j] = max(match, notMatch);
    }
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m - 1, s, t, dp);
    }
};

// link : https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25