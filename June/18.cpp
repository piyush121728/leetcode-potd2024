#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &d, vector<int> &p, vector<int> &c)
    {
        int m = c.size(), n = d.size();
        priority_queue<int> pq;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({d[i], p[i]});
        }
        sort(v.begin(), v.end());
        sort(c.begin(), c.end());

        int res = 0;
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            while (j < n && v[j].first <= c[i])
            {
                pq.push(v[j].second);
                j++;
            }
            if (j != 0)
            {
                res += pq.top();
            }
        }

        return res;
    }
};

// link : https://leetcode.com/problems/most-profit-assigning-work/submissions/1301691225/?envType=daily-question&envId=2024-06-18