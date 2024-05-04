#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &p, int l)
    {
        int n = p.size();
        int cnt = 0;
        int i = 0, j = n - 1;
        sort(p.begin(), p.end());
        while (i < j)
        {
            if (p[i] + p[j] <= l)
            {
                cnt++;
                i++;
                j--;
            }
            else
            {
                cnt++;
                j--;
            }
        }

        if (i == j)
        {
            cnt++;
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/boats-to-save-people/?envType=daily-question&envId=2024-05-04