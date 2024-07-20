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
    bool findPath(TreeNode *lca, int tar, string &path)
    {
        if (lca == NULL)
        {
            return false;
        }
        if (lca->val == tar)
        {
            return true;
        }

        path.push_back('L');
        if (findPath(lca->left, tar, path))
        {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if (findPath(lca->right, tar, path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
    {
        if (!root)
        {
            return NULL;
        }

        if (root->val == p || root->val == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && !right)
        {
            return left;
        }
        else if (!left && right)
        {
            return right;
        }
        else if (left && right)
        {
            return root;
        }

        return NULL;
    }
    string getDirections(TreeNode *root, int s, int d)
    {
        TreeNode *lca = lowestCommonAncestor(root, s, d);
        cout << lca->val << endl;
        string lcaToS = "", lcaToD = "";
        findPath(lca, s, lcaToS);
        findPath(lca, d, lcaToD);
        cout << lcaToS << endl;
        cout << lcaToD << endl;

        for (auto &ch : lcaToS)
        {
            ch = 'U';
        }

        return lcaToS + lcaToD;
    }
};

// link : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/?envType=daily-question&envId=2024-07-16