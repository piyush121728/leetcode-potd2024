#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 2)
            return {0, 1};
        if (n == 1)
            return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto &i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
            {
                q.push(i);
                degree[i]--;
            }
        }
        int nodes = n;
        while (!q.empty())
        {
            int n = q.size();
            nodes -= n;
            while (n--)
            {
                int x = q.front();
                q.pop();
                for (int &i : adj[x])
                    if (--degree[i] == 1)
                        q.push(i);
            }
            if (nodes <= 2)
                break;
        }
        vector<int> ans;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
        }
        return ans;
    }
};

// link : https://leetcode.com/problems/minimum-height-trees/?envType=daily-question&envId=2024-04-23