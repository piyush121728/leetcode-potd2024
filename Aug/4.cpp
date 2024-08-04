#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                sum %= 1000000007;

                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = left - 1; i < right; i++)
        {
            res += v[i];
            res %= 1000000007;
        }
        return res;
    }
};

// link : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-08-04