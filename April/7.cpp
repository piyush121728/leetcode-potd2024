#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rec(int i, int cnt, string s, int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return cnt == 0;
        }

        if (dp[i][cnt] != -1)
        {
            return dp[i][cnt];
        }

        bool isValid = false;
        if (s[i] == '(')
        {
            isValid = rec(i + 1, cnt + 1, s, n, dp);
        }
        else if (cnt > 0 && s[i] == ')')
        {
            isValid = rec(i + 1, cnt - 1, s, n, dp);
        }
        else if (s[i] == '*')
        {
            isValid |= rec(i + 1, cnt + 1, s, n, dp);
            isValid |= rec(i + 1, cnt, s, n, dp);
            if (cnt > 0)
            {
                isValid |= rec(i + 1, cnt - 1, s, n, dp);
            }
        }

        return dp[i][cnt] = isValid;
    }
    bool checkValidString(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(0, 0, s, n, dp);
    }
};


// link : https://leetcode.com/problems/valid-parenthesis-string/?envType=daily-question&envId=2024-04-07