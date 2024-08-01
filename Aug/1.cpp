#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int dp[1001][1001];
    int rec(int i, int remW, int maxH, vector<vector<int>> &b, int w)
    {
        if (i >= n)
        {
            return maxH;
        }

        if (dp[i][remW] != -1)
        {
            return dp[i][remW];
        }

        int bW = b[i][0], bH = b[i][1];
        int take = INT_MAX, notTake = INT_MAX;

        if (bW <= remW)
        {
            take = rec(i + 1, remW - bW, max(maxH, bH), b, w);
        }
        notTake = maxH + rec(i + 1, w - bW, bH, b, w);
        return dp[i][remW] = min(take, notTake);
    }
    int minHeightShelves(vector<vector<int>> &b, int w)
    {
        memset(dp, -1, sizeof(dp));
        n = b.size();
        return rec(0, w, 0, b, w);
    }
};

// link : https://leetcode.com/problems/number-of-senior-citizens/submissions/1340789847/?envType=daily-question&envId=2024-08-01