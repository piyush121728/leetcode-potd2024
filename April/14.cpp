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
    void traverse(TreeNode *root, int &sum)
    {
        if (!root)
        {
            return;
        }
        if (root->left &&
            !root->left->left &&
            !root->left->right)
        {
            sum += root->left->val;
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        traverse(root, sum);
        return sum;
    }
};

// link : https://leetcode.com/problems/sum-of-left-leaves/?envType=daily-question&envId=2024-04-14