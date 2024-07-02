#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp1, mp2;

        for (auto x : nums1)
        {
            mp1[x]++;
        }
        for (auto x : nums2)
        {
            mp2[x]++;
        }

        vector<int> ans;
        for (auto it : mp1)
        {
            if (mp2[it.first] > 0)
            {
                for (int i = 0; i < min(it.second, mp2[it.first]); i++)
                {
                    ans.push_back(it.first);
                }
            }
        }

        return ans;
    }
};