#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
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
    bool traverse(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return root->val;
        }

        bool left = traverse(root->left);
        bool right = traverse(root->right);

        if (root->val == 2)
        {
            return left | right;
        }
        else
        {
            return left & right;
        }
    }
    bool evaluateTree(TreeNode *root)
    {
        return traverse(root);
    }
};

// link : https://leetcode.com/problems/evaluate-boolean-binary-tree/