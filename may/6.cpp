#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        auto temp = head;
        stack<ListNode *> st;
        while (temp)
        {
            while (st.size() != 0 && temp->val > st.top()->val)
            {
                st.pop();
            }
            st.push(temp);
            temp = temp->next;
        }
        stack<ListNode *> rev;
        while (!st.empty())
        {
            rev.push(st.top());
            st.pop();
        }

        ListNode *thead = new ListNode(-1);
        temp = thead;
        while (!rev.empty())
        {
            temp->next = rev.top();
            rev.pop();
            temp = temp->next;
        }

        return thead->next;
    }
};

// link : https://leetcode.com/problems/remove-nodes-from-linked-list/?envType=daily-question&envId=2024-05-06