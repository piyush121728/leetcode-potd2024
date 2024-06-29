#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        multiset<int> st;
        int res = 0, i = 0, j = 0, n = nums.size();

        while (j < n)
        {
            st.insert(nums[j]);
            int mini = *st.begin();
            int maxi = *st.rbegin();

            while (i <= j && maxi - mini > limit)
            {
                st.erase(st.lower_bound(nums[i]));
                i++;
                mini = *st.begin();
                maxi = *st.rbegin();
            }

            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};

// link : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/?envType=daily-question&envId=2024-06-23