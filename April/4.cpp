#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int cnt = 0;
        int maxi = 0;
        for (auto &x : s)
        {
            if (x == '(')
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else if (x == ')')
            {
                cnt--;
            }
        }

        return maxi;
    }
};

// link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2024-04-04