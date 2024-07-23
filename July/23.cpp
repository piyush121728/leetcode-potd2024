#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }

        vector<pair<int, int>> v;
        for (auto &[key, val] : mp)
        {
            v.push_back({val, key});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        int n = v.size();

        int i = 0, j = 0;

        while (i < n && j < n)
        {
            int freq = v[i].first;

            while (j < n && v[j].first == freq)
            {
                j++;
            }
            reverse(v.begin() + i, v.begin() + j);
            i = j;
        }

        for (auto &[val, key] : v)
        {
            for (int i = 0; i < val; i++)
            {
                ans.push_back(key);
            }
        }

        return ans;
    }
};

// link : https://leetcode.com/problems/sort-array-by-increasing-frequency/?envType=daily-question&envId=2024-07-23