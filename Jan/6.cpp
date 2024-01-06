#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dp;
    int n;
    int getNextIndex(vector<vector<int>> &arr, int l, int tar)
    {
        int r = n - 1;

        int result = n + 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid][0] >= tar)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>> &arr, int i)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int next = getNextIndex(arr, i + 1, arr[i][1]);

        int taken = arr[i][2] + solve(arr, next);
        int notTaken = solve(arr, i + 1);

        return dp[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int> &s, vector<int> &e, vector<int> &p)
    {
        n = s.size();

        dp.resize(n + 1, -1);

        vector<vector<int>> arr(n, vector<int>(3)); //{s, e, p}

        for (int i = 0; i < n; i++)
        {
            arr[i] = {s[i], e[i], p[i]};
        }

        sort(arr.begin(), arr.end());

        return solve(arr, 0);
    }
};

int main()
{
    return 0;
}

// link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/