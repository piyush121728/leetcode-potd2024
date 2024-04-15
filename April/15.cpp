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
    void rec(TreeNode *root, string str, int &sum)
    {
        if (!root)
        {
            return;
        }

        str.push_back('0' + root->val);
        if (!root->left && !root->right)
        {
            sum += stoi(str);
        }
        rec(root->left, str, sum);
        rec(root->right, str, sum);
        str.pop_back();
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        rec(root, "", sum);
        return sum;
    }
};

// link : https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=daily-question&envId=2024-04-15