#include <bits/stdc++.h>
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

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> adj[n];
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<vector<int>> allPairShortestDist;
        for (int src = 0; src < n; src++)
        {
            vector<int> dist = dijkstra(n, adj, src);
            allPairShortestDist.push_back(dist);
        }

        int cityNo = -1;
        int cities = n;

        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                cout << allPairShortestDist[city][adjCity] << " ";
                if (allPairShortestDist[city][adjCity] <= distanceThreshold)
                {
                    count++;
                }
            }
            cout << endl;

            if (count <= cities)
            {
                cities = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};


// link :https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/?envType=daily-question&envId=2024-07-26