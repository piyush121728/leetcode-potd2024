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
    int maxDiff = -1;
    void solve(TreeNode *root, TreeNode *child)
    {
        if (!root || !child)
        {
            return;
        }

        maxDiff = max({maxDiff, abs(root->val - child->val)});
        solve(root, child->left);
        solve(root, child->right);
    }
    void traversal(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        solve(root, root->left);
        solve(root, root->right);

        traversal(root->right);
        traversal(root->left);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        traversal(root);
        return maxDiff;
    }
};

// link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11