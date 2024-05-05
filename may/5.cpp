#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *curr)
    {
        while (curr->next->next)
        {
            auto next = curr->next;
            curr->val = next->val;
            curr = next;
        }
        auto next = curr->next;
        curr->val = next->val;
        curr->next = NULL;
    }
};

// https://leetcode.com/problems/delete-node-in-a-linked-list/?envType=daily-question&envId=2024-05-05