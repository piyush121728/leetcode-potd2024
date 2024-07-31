#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &r)
    {
        int n = r.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < j; k++)
                {
                    if ((r[i] > r[j] && r[j] > r[k]) || (r[i] < r[j] && r[j] < r[k]))
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

// link : https://leetcode.com/problems/count-number-of-teams/?envType=daily-question&envId=2024-07-29