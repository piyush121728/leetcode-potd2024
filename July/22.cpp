#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> sortPeople(vector<string> &n, vector<int> &h)
    {
        vector<pair<int, string>> v;

        int s = n.size();
        for (int i = 0; i < s; i++)
        {
            v.push_back({h[i], n[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, string>>());
        vector<string> strs;
        for (auto e : v)
        {
            strs.push_back(e.second);
        }
        return strs;
    }
};

// link : https://leetcode.com/problems/sort-the-people/submissions/1329696648/?envType=daily-question&envId=2024-07-22