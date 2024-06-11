#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<long long, int> mp;
        long long sum = 0;
        mp[sum % k]++;
        int res = 0;
        int cnt = 0;
        for (auto x : nums)
        {
            sum += x;
            if (x % k == 0)
            {
                cnt++;
            }
            int rem = sum % k;
            if (rem < 0)
            {
                rem += k;
            }
            res += mp[rem];
            mp[rem]++;
        }

        return res - cnt > 0;
    }
};

// link : https://leetcode.com/problems/continuous-subarray-sum/submissions/?envType=daily-question&envId=2024-06-08