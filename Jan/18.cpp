#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // pure recursion takes TC : O(2^n) and SC: O(n)-->stack space;
    // recursion with dp[] (memoization or top-down approach) takes TC : O(n) and SC: O(n) + O(N)-->stack space and dp[n];
    /*
    int climbStairs(int n,vector<int>&dp)
    {
        if(n==0 || n==1)
        {
            return 1;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        return dp[n] = climbStairs(n-1,dp) + climbStairs(n-2,dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp(n+1,-1);
        return climbStairs(n,dp);
    }
    */
    // tabulation(bottom-up) takes TC : O(n) and SC: O(n)-->dp[n];
    int climbStairs(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

};

// link : https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18