#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> adj[100001];
    int vis[100001] = {0};

    void dfs(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        if (root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left);
        }

        if (root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }

    int amountOfTime(TreeNode *root, int start)
    {
        dfs(root);
        queue<pair<int, int>> pn;

        int time = 0;
        pn.push({start, 0});
        vis[start] = 1;

        while (!pn.empty())
        {
            auto top = pn.front();
            pn.pop();
            int node = top.first;
            int t = top.second;
            time = max(time, t);

            for (auto adjNode : adj[node])
            {
                if (!vis[adjNode])
                {
                    pn.push({adjNode, t + 1});
                    vis[adjNode] = 1;
                }
            }
        }
        return time;
    }
};

// link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10