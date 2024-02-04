#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rec(int i, int k, vector<int> &arr, int n, vector<int> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int maxi = -1, res = 0;
        for (int j = i; j < min(i + k, n); j++)
        {
            maxi = max(maxi, arr[j]);
            res = max(res, (maxi * (j - i + 1)) + rec(j + 1, k, arr, n, dp));
        }
        return dp[i] = res;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return rec(0, k, arr, n, dp);
    }
};

// link : https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03