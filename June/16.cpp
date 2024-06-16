#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {

        long long m = nums.size(), maxi = 0, cnt = 0, i = 0;

        while (maxi < n)
        {
            if (i < m && nums[i] <= maxi + 1)
            {
                maxi += nums[i];
                i++;
            }
            else
            {
                maxi += (maxi + 1);
                cnt++;
            }
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/patching-array/?envType=daily-question&envId=2024-06-16