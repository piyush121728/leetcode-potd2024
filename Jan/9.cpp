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
    bool leafSimilar(TreeNode *r1, TreeNode *r2)
    {
        vector<int> l1, l2;
        traversal(r1, l1);
        traversal(r2, l2);

        return l1 == l2;
    }

    void traversal(TreeNode *node, vector<int> &l)
    {
        if (node == NULL)
        {
            return;
        }
        if (node->left == NULL && node->right == NULL)
        {
            l.push_back(node->val);
        }
        traversal(node->left, l);
        traversal(node->right, l);
    }
};

int main()
{
    return 0;
}

// link : https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09