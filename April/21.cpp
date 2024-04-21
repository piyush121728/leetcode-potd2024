#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int s, int d, vector<int> adj[], vector<int> &vis)
    {
        vis[s] = 1;
        if (s == d)
        {
            return true;
        }

        for (auto adjNode : adj[s])
        {
            if (!vis[adjNode])
            {
                if (dfs(adjNode, d, adj, vis) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int s, int d)
    {
        vector<int> adj[n];
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);

        return dfs(s, d, adj, vis);
    }
};

// link : https://leetcode.com/problems/find-if-path-exists-in-graph/?envType=daily-question&envId=2024-04-21