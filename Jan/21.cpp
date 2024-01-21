#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int robHelper(vector<int> &nums, int n, vector<int> &dp)
    {
        // base case
        if (n <= 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        // recursive call or induction hypothesis
        int exclude = robHelper(nums, n - 1, dp);
        int include = robHelper(nums, n - 2, dp);

        int ans = max(exclude, include + nums[n - 1]);
        // save for future use;
        dp[n] = ans;
        // induction step
        return ans;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        return robHelper(nums, n, dp);
    }
};

// link : https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21