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
    ListNode *doubleIt(ListNode *head)
    {
        stack<ListNode *> st;
        auto temp = head;
        while (temp)
        {
            st.push(temp);
            temp = temp->next;
        }

        int c = 0;

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            int num = (it->val * 2) + c;
            c = num / 10;
            int d = num % 10;
            it->val = d;
        }

        if (c > 0)
        {
            ListNode *newHead = new ListNode(c);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};

// link : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07