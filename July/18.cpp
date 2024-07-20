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
    unordered_map<TreeNode *, vector<TreeNode *>> adj;
    set<TreeNode *> leaf;
    void makeGraph(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            leaf.insert(root);
            return;
        }

        if (root->left)
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }
        if (root->right)
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }

        makeGraph(root->left);
        makeGraph(root->right);
    }
    int countPairs(TreeNode *root, int d)
    {
        makeGraph(root);
        int cnt = 0;

        for (auto src : leaf)
        {
            cout << src->val << endl;
            set<TreeNode *> vis;
            queue<pair<TreeNode *, int>> pn;
            pn.push({src, 0});
            vis.insert(src);

            while (!pn.empty())
            {
                auto nodeInfo = pn.front();
                pn.pop();
                TreeNode *node = nodeInfo.first;
                int dist = nodeInfo.second;
                if (leaf.count(node) > 0 && dist > 0 && dist <= d)
                {
                    cnt++;
                }

                for (auto adjNode : adj[node])
                {
                    if (vis.find(adjNode) == vis.end() && dist + 1 <= d)
                    {
                        pn.push({adjNode, dist + 1});
                        vis.insert(adjNode);
                    }
                }
            }
        }

        return cnt / 2;
    }
};

// link : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
