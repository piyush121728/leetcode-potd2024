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
    TreeNode *dfs(TreeNode *root, set<int> &st, vector<TreeNode *> &roots)
    {
        if (!root)
        {
            return root;
        }
        root->left = dfs(root->left, st, roots);
        root->right = dfs(root->right, st, roots);
        if (st.count(root->val))
        {
            if (root->left)
            {
                roots.push_back(root->left);
            }
            if (root->right)
            {
                roots.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode *> roots;
        if (st.count(root->val) == 0)
        {
            roots.push_back(root);
        }
        dfs(root, st, roots);
        return roots;
    }
};