#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};

// link : https://leetcode.com/problems/squares-of-a-sorted-array/?envType=daily-question&envId=2024-03-02