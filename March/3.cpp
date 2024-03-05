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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int tot = 0;
        auto temp = head;
        while (temp)
        {
            tot++;
            temp = temp->next;
        }
        if (tot == n)
        {
            return head->next;
        }

        int i = tot - n;
        temp = head;
        i--;
        while (i--)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};
// link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03