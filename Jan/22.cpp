#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int rep = 0, miss = 0, n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0), actTot = (n * (n + 1)) / 2;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                rep = nums[i];
                break;
            }
        }

        totSum -= rep;
        miss = actTot - totSum;

        return {rep, miss};
    }
};

// link : https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22