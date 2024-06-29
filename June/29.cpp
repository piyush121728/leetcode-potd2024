#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int src, vector<vector<int>> &adj, vector<vector<int>> &res, vector<int> &vis)
    {
        vis[src] = 1;
        for (auto adjNode : adj[src])
        {
            if (!vis[adjNode])
            {
                res[adjNode].push_back(i);
                dfs(i, adjNode, adj, res, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n), res(n);

        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> vis(n, 0);
            dfs(i, i, adj, res, vis);
        }
        return res;
    }
};

// link : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/submissions/