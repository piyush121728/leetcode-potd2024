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
    int res = 0;

    void solve(TreeNode *root, vector<int> &freq)
    {
        if (root != NULL)
        {
            freq[root->val]++;

            if (root->left == NULL && root->right == NULL)
            {
                int oddFreq = 0;
                for (int i = 1; i <= 9; i++)
                {
                    if (freq[i] % 2 != 0)
                    {
                        oddFreq++;
                    }
                }

                res += oddFreq <= 1;
            }

            solve(root->left, freq);
            solve(root->right, freq);

            freq[root->val]--;
        }
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10, 0);

        solve(root, freq);
        return res;
    }

    // link : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
};