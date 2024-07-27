#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        // initial configuration for dijkstra alog
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int shorDist = it.first;

            for (auto adjacent : adj[node])
            {
                int adjNode = adjacent[0];
                int edgW = adjacent[1];

                if (shorDist + edgW < dist[adjNode])
                {
                    dist[adjNode] = shorDist + edgW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

    long long minimumCost(string src, string tar, vector<char> &ori, vector<char> &cha, vector<int> &cost)
    {

        int n = src.size(), m = ori.size();
        vector<vector<int>> adj[26];

        for (int i = 0; i < m; i++)
        {
            adj[ori[i] - 'a'].push_back({cha[i] - 'a', cost[i]});
        }

        vector<vector<int>> allPairShortestDist;
        for (int src = 0; src < 26; src++)
        {
            vector<int> dist = dijkstra(26, adj, src);
            allPairShortestDist.push_back(dist);
        }

        long long costs = 0;

        for (int i = 0; i < n; i++)
        {
            if (allPairShortestDist[src[i] - 'a'][tar[i] - 'a'] == 1e9)
            {
                return -1;
            }
            costs += allPairShortestDist[src[i] - 'a'][tar[i] - 'a'];
        }

        return costs;
    }
};

// link : https://leetcode.com/problems/minimum-cost-to-convert-string-i/?envType=daily-question&envId=2024-07-27
