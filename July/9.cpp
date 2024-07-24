#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &c)
    {
        int s = 0, f = 0;
        double w = 0;
        for (auto e : c)
        {
            if (e[0] > f)
            {
                f = e[0] + e[1];
            }
            else
            {
                f = f + e[1];
            }
            w += f - e[0];
        }
        double n = c.size();
        return w / n;
    }
};

// link : https://leetcode.com/problems/average-waiting-time/submissions/1330363159/?envType=daily-question&envId=2024-07-09