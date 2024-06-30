#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    // intial configuration
    vector<int> parent, rank, size; // parent->to store the ultimate parent of ith node and rank->to store the rank of ith node

    // constructor
    // Both for O based vertices or 1 based vertices
    DisjointSet(int n) // n->number of vertices
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // function to find the ultimate parent of a node

    /*
    //This function find ultimate partent of a node in O(log n)
    int findUPar(int node)
    {
        //base case;
        if(node==parent[node])
        {
            return node;
        }

        //induction hypothesis
        return findUPar(parent[node]);
    }
    */

    // In order to reduce the time complextiy of findUPar we can apply path compression technique on it
    // which will take O(const) to find the ultimate parent of a node
    // TC : O(4 alpha) = O(1)
    //  SC : O(1)
    int findUPar(int node)
    {
        // base case;
        if (node == parent[node])
        {
            return node;
        }

        // induction hypothesis
        return parent[node] = findUPar(parent[node]);
    }

    // union by rank
    // TC : O(4 alpha) + O(4 alpha) = O(1)
    // SC : O(1)

    void unionByRank(int u, int v)
    {
        // step 1 : find the ultimate parent of u and v
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        // when both ulp_u and ulp_v belong to same parent(same compo) then we simply return
        if (ulp_u == ulp_v)
        {
            return;
        }

        // step 2 : find the rank of ulp_u and ulp_v
        int ulp_u_r = rank[ulp_u], ulp_v_r = rank[ulp_v];

        // step 3 : connect the smaller rank to the larger rank always
        if (ulp_u_r < ulp_v_r)
        {
            parent[ulp_u] = ulp_v;
        }
        else if (ulp_u_r > ulp_v_r)
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // if ulp_u_r and ulp_v_r are same, then we can connect either ulp_u_r to ulp_v_r or ulp_v_r to ulp_u_r
            parent[ulp_v] = ulp_u;
            // In this case, we need to increase the rank by one because ulp_u_r and ulp_v_r are same,
            // if we connect either ulp_u_r to ulp_v_r or ulp_v_r to ulp_u_r then height of either ulp_v_r and ulp_u_r will be increase by one respectively
            rank[ulp_u]++;
        }
    }

    // union by size
    // TC : O(4 alpha) + O(4 alpha) = O(1)
    // SC : O(1)
    void unionBySize(int u, int v)
    {
        // step 1 : find the ultimate parent of u and v
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        // when both ulp_u and ulp_v belong to same parent(same compo) then we simply return
        if (ulp_u == ulp_v)
        {
            return;
        }
        // step 2 : find the size of ulp_u and ulp_v
        int ulp_u_s = rank[ulp_u], ulp_v_s = rank[ulp_v];

        // step 3 : connect the smaller size to the larger size always
        if (ulp_u_s < ulp_v_s)
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DisjointSet g1(n), g2(n);
        int cnt = 0;
        for (auto e : edges)
        {
            if (e[0] == 3)
            {
                int u = e[1], v = e[2];
                if (g1.findUPar(u) != g1.findUPar(v))
                {
                    g1.unionBySize(u, v);
                    g2.unionBySize(u, v);
                }
                else
                {
                    cnt++;
                }
            }
        }

        for (auto e : edges)
        {
            int u = e[1], v = e[2];
            if (e[0] == 1)
            {
                if (g1.findUPar(u) != g1.findUPar(v))
                {
                    g1.unionBySize(u, v);
                }
                else
                {
                    cnt++;
                }
            }
            else if (e[0] == 2)
            {
                if (g2.findUPar(u) != g2.findUPar(v))
                {
                    g2.unionBySize(u, v);
                }
                else
                {
                    cnt++;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (g1.findUPar(i) != g1.findUPar(i + 1))
            {
                return -1;
            }
            if (g2.findUPar(i) != g2.findUPar(i + 1))
            {
                return -1;
            }
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/?envType=daily-question&envId=2024-06-30