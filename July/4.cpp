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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *temp = head->next;
        int sum = 0;
        ListNode *thead = NULL;
        ListNode *temp2 = NULL;
        while (temp)
        {
            sum += temp->val;
            if (temp->val == 0)
            {
                if (!thead)
                {
                    thead = new ListNode(sum);
                    temp2 = thead;
                }
                else
                {
                    temp2->next = new ListNode(sum);
                    temp2 = temp2->next;
                }
                sum = 0;
            }
            temp = temp->next;
        }
        return thead;
    }
};