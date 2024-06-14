#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int res = 0;
        set<int> st;
        st.insert(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (st.count(nums[i]) > 0)
            {
                res += abs(nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }

            st.insert(nums[i]);
        }

        return res;
    }
};

// link : https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14