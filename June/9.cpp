#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<long long, int> mp;
        long long sum = 0;
        mp[sum % k]++;
        int res = 0;
        for (auto x : nums)
        {
            sum += x;
            int rem = sum % k;
            if (rem < 0)
            {
                rem += k;
            }
            res += mp[rem];
            mp[rem]++;
        }

        return res;
    }
};

// link : https://leetcode.com/problems/subarray-sums-divisible-by-k/?envType=daily-question&envId=2024-06-09