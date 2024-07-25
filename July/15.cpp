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
    TreeNode *createBinaryTree(vector<vector<int>> &d)
    {
        set<int> st;
        for (auto e : d)
        {
            st.insert(e[0]);
            st.insert(e[1]);
        }

        unordered_map<int, TreeNode *> mp;

        for (auto e : d)
        {
            int u = e[0], v = e[1], isL = e[2];
            if (st.count(e[1]))
            {
                st.erase(e[1]);
            }
            if (mp[u] && mp[v])
            {
                if (isL)
                {
                    mp[u]->left = mp[v];
                }
                else
                {
                    mp[u]->right = mp[v];
                }
            }
            else if (mp[u])
            {
                if (isL)
                {
                    mp[u]->left = new TreeNode(v);
                    mp[v] = mp[u]->left;
                }
                else
                {
                    mp[u]->right = new TreeNode(v);
                    mp[v] = mp[u]->right;
                }
            }
            else if (mp[v])
            {
                TreeNode *root = new TreeNode(u);
                if (isL)
                {
                    root->left = mp[v];
                }
                else
                {
                    root->right = mp[v];
                }
                mp[u] = root;
            }
            else
            {
                TreeNode *root = new TreeNode(u);
                if (isL)
                {

                    root->left = new TreeNode(v);
                    mp[v] = root->left;
                }
                else
                {
                    root->right = new TreeNode(v);
                    mp[v] = root->right;
                }
                mp[u] = root;
            }
        }

        return mp[*st.begin()];
    }
};

// link : https://leetcode.com/problems/create-binary-tree-from-descriptions/?envType=daily-question&envId=2024-07-15