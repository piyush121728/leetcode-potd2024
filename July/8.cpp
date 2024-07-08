#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }

        while (q.size() != 1)
        {
            for (int i = 1; i < k; i++)
            {
                int ele = q.front();
                q.pop();
                q.push(ele);
            }
            q.pop();
        }

        return q.front();
    }
};

// link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/?envType=daily-question&envId=2024-07-08