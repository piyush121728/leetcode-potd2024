#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        if (nums.size() % 3 != 0)
        {
            return {};
        }
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i + 2] - nums[i] <= k)
            {
                ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
            }
            else
            {
                return {};
            }
        }

        return ans;
    }
};

// link : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01