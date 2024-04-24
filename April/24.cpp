#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    int rec(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        return dp[n] = rec(n - 1) + rec(n - 2) + rec(n - 3);
    }

    int tribonacci(int n)
    {
        dp.resize(n + 1, -1);
        return rec(n);
    }
};

// link : https://leetcode.com/problems/n-th-tribonacci-number/submissions/1240914447/?envType=daily-question&envId=2024-04-24