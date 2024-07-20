#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rSum, vector<int> &cSum)
    {
        int n = rSum.size(), m = cSum.size(), i = 0, j = 0;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        while (i < n && j < m)
        {
            int mini = min(rSum[i], cSum[j]);
            ans[i][j] = mini;
            rSum[i] -= mini;
            cSum[j] -= mini;
            if (rSum[i] == 0)
            {
                i++;
            }
            if (cSum[j] == 0)
            {
                j++;
            }
        }

        return ans;
    }
};

// link : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20