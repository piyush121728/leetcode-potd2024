#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &p, vector<int> &c)
    {
        int n = p.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({p[i], c[i]});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        priority_queue<int> pq;
        int i = 0;
        while (k--)
        {
            while (i < n && vec[i].first <= w)
            {
                pq.push(vec[i].second);
                i++;
            }

            if (pq.empty())
            {
                break;
            }
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

// link : https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1