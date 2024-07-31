#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int n, vector<vector<int>> adj[], int src, int change)
    {
        // initial configuration for dijkstra alog
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> dist2(n + 1, 1e9);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto [shortDist, node] = pq.top();
            pq.pop();

            int d = (shortDist / change);
            if (d % 2 == 1)
            {
                shortDist = (d + 1) * change;
            }

            for (auto adjacent : adj[node])
            {
                int adjNode = adjacent[0];
                int edgW = adjacent[1];

                if (dist[adjNode] > shortDist + edgW)
                {
                    dist2[adjNode] = dist[adjNode];
                    dist[adjNode] = shortDist + edgW;
                    pq.push({dist[adjNode], adjNode});
                }
                else if (dist2[adjNode] > shortDist + edgW && dist[adjNode] != shortDist + edgW)
                {
                    dist2[adjNode] = shortDist + edgW;
                    pq.push({dist2[adjNode], adjNode});
                }
            }
        }
        return dist2;
    }

    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj[n + 1];
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], time});
            adj[e[1]].push_back({e[0], time});
        }

        vector<int> secMinDist = dijkstra(n, adj, 1, change);
        return secMinDist[n];
    }
};
// link : https://leetcode.com/problems/second-minimum-time-to-reach-destination/submissions/1339162471/?envType=daily-question&envId=2024-07-28-