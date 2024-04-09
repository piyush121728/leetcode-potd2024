#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        queue<pair<int, int>> q;
        int n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            q.push({tickets[i], i});
        }
        int cnt = 0;
        while (q.size() != 0)
        {
            auto it = q.front();
            q.pop();
            it.first--;
            cnt++;
            if (it.first == 0 )
            {
                if (it.second == k)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            q.push(it);
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/1227562202/?envType=daily-question&envId=2024-04-09