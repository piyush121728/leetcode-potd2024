

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int n;
    vector<vector<int>> dp;
    int rec(int i, int j, vector<int> &nums)
    {

        if (i < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int notTake = rec(i - 1, j, nums);
        int take = 0;
        if (j == n || nums[i] < nums[j])
        {
            take = rec(i - 1, i, nums) + 1;
        }

        return dp[i][j] = max(take, notTake);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        dp.resize(n, vector<int>(n + 1, -1));

        return rec(n - 1, n, nums);
    }
};

int main()
{
    return 0;
}

// link : https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=daily-question&envId=2024-01-05