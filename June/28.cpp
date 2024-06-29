#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, int> mp;
        for (auto e : edges)
        {
            mp[e[0]]++;
            mp[e[1]]++;
        }

        vector<pair<int, int>> v;
        for (auto it : mp)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        for (int i = 0; i < v.size(); i++)
        {
            mp[v[i].second] = n - i;
        }

        long long res = 0;
        for (auto e : edges)
        {
            res += mp[e[0]];
            res += mp[e[1]];
        }

        return res;
    }
};
// link :https://leetcode.com/problems/maximum-total-importance-of-roads/?envType=daily-question&envId=2024-06-28