#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                mini = min(mini, mat[i][j]);
            }
            mp[mini]++;
        }
        for (int i = 0; i < m; i++)
        {
            int maxi = INT_MIN;
            for (int j = 0; j < n; j++)
            {
                maxi = max(maxi, mat[j][i]);
            }
            mp[maxi]++;
            if (mp[maxi] == 2)
            {
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};

// link : https://leetcode.com/problems/lucky-numbers-in-a-matrix/submissions/1326217229/?envType=daily-question&envId=2024-07-19