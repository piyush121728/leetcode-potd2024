#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> mp;
        int n = edges.size();

        for (auto e : edges)
        {
            mp[e[0]]++;
            mp[e[1]]++;
        }
        int ans = 0;
        for (auto it : mp)
        {
            if (it.second == n)
            {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};

// link : https://leetcode.com/problems/find-center-of-star-graph/?envType=daily-question&envId=2024-06-27