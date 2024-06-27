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
    void traverse(TreeNode *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);
    }
    TreeNode *buildTree(vector<int> &v, int l, int r)
    {
        if (l > r)
        {
            return NULL;
        }
        int mid = (l + r) / 2;
        TreeNode *newRoot = new TreeNode(v[mid]);
        newRoot->left = buildTree(v, l, mid - 1);
        newRoot->right = buildTree(v, mid + 1, r);
        return newRoot;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> v;
        traverse(root, v);
        int n = v.size();
        return buildTree(v, 0, n - 1);
    }
};

// link : https://leetcode.com/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2024-06-26