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
    TreeNode *traverse(TreeNode *root, int val, int depth, int curr)
    {
        if (!root)
        {
            return NULL;
        }

        if (curr == depth - 1)
        {
            auto left = root->left;
            auto right = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = left;
            root->right->right = right;
            return root;
        }
        root->left = traverse(root->left, val, depth, curr + 1);
        root->right = traverse(root->right, val, depth, curr + 1);
        return root;
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return traverse(root, val, depth, 1);
    }
};

// link : https://leetcode.com/problems/add-one-row-to-tree/?envType=daily-question&envId=2024-04-16