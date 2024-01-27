#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion : TC : O(k^n)
    // memoization : TC : O(k*n*min(k,n-1));
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int rec(int n, int k)
    {
        if (n == 0)
        { // we can't from any array without any element
            return 0;
        }

        if (k == 0)
        {
            return 1; // valid only will be only one
        }

        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }

        int res = 0;
        for (int j = 0; j <= min(k, n - 1); j++)
        {
            res = ((res % mod) + (rec(n - 1, k - j) % mod)) % mod;
        }
        return dp[n][k] = res;
    }

    int kInversePairs(int n, int k)
    {
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return rec(n, k);
    }
};

// link : https://leetcode.com/problems/k-inverse-pairs-array/editorial/?envType=daily-question&envId=2024-01-27