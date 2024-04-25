#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.length();
        vector<int> t(26, 0);
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            int l = max(0, c - k);
            int r = min(25, c + k);

            int currMaxi = 0;
            for (int j = l; j <= r; j++)
            {
                currMaxi = max(currMaxi, t[j]);
            }

            t[c] = max(t[c], currMaxi + 1);
            res = max(res, t[c]);
        }

        return res;
    }
};

// link : https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25
