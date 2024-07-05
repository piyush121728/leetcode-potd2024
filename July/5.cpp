#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        if (res.size() < 3)
        {
            return {-1, -1};
        }
        vector<int> indi;
        for (int i = 1; i < res.size() - 1; i++)
        {
            if ((res[i] > res[i - 1] && res[i] > res[i + 1]) || (res[i] < res[i - 1] && res[i] < res[i + 1]))
            {
                indi.push_back(i);
            }
        }
        if (indi.size() < 2)
        {
            return {-1, -1};
        }
        int mini = INT_MAX;
        for (int i = 1; i < indi.size(); i++)
        {
            mini = min(mini, indi[i] - indi[i - 1]);
        }

        int maxi = indi[indi.size() - 1] - indi[0];
        return {mini, maxi};
    }
};

// link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2024-07-05