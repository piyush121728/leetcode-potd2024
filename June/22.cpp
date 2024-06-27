#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int cnt = 0;
        int n = nums.size();

        int i = 0;
        int j = 0;
        int c = 0;
        while (i < n)
        {
            while (i < n && c <= k)
            {
                if (nums[i] % 2 == 1)
                {
                    c++;
                }
                if (c == k)
                {
                    cnt++;
                }
            }
            while (j < i && c != k)
            {
                if (nums[j] % 2 == 1)
                {
                    c--;
                }
                j--;
            }
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/count-number-of-nice-subarrays/?envType=daily-question&envId=2024-06-22