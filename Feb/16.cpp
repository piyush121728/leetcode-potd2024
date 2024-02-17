#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        if (!root)
        {
            return NULL;
        }

        Node *head = flattenBST(root->left);
        root->left = NULL;
        Node *temp = head;
        while (temp && temp->right)
        {
            temp = temp->right;
        }
        if (head)
        {
            temp->right = root;
        }
        else
        {
            head = root;
        }

        root->right = flattenBST(root->right);

        return head;
    }
};

// link : https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1