#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &c, vector<int> &g, int m)
    {
        int n = c.size();
        int res = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (g[i] == 0)
            {
                res += c[i];
            }
            if (i < m)
            {
                if (g[i] == 1)
                {
                    sum += c[i];
                }
            }
        }
        
        int i = 0;
        int maxi = sum;
        for (int j = m; j < n; j++)
        {
            if (g[j] == 1)
            {
                sum += c[j];
            }
            if (g[i] == 1)
            {
                sum -= c[i];
            }

            maxi = max(sum, maxi);
            i++;
        }

        return res + maxi;
    }
};

// link : https://leetcode.com/problems/grumpy-bookstore-owner/?envType=daily-question&envId=2024-06-21