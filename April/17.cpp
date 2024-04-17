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
    
        void travers(TreeNode *root, string str, vector<string> &st)
        {
            if (!root)
            {
                return;
            }
            str.push_back('a' + root->val);
            if (!root->left && !root->right)
            {
                reverse(str.begin(), str.end());
                st.push_back(str);
                cout << str << endl;
            }
            travers(root->left, str, st);
            travers(root->right, str, st);
            str.pop_back();
        }
        string smallestFromLeaf(TreeNode *root)
        {
            vector<string> st;
            string str = "";
            travers(root, str, st);
            sort(st.begin(), st.end());
            return st[0];
        }
    
};

// link : https://leetcode.com/problems/smallest-string-starting-from-leaf/?envType=daily-question&envId=2024-04-17