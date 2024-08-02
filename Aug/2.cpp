#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int size = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (n == size)
        {
            return 0;
        }
        int i = 0, j = 0;
        int cnt = 0;
        while (j < size)
        {
            cnt += nums[j];
            j++;
        }

        int swaps = size - cnt;

        while (i < n)
        {
            cnt -= nums[i];
            cnt += nums[j];
            swaps = min(swaps, size - cnt);
            i++;
            j++;
            j %= n;
        }

        return swaps;
    }
};

// link : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/submissions/1136523214/?envType=daily-question&envId=2024-08-02