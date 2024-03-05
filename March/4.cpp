#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int ans = 0;
        sort(tokens.begin(), tokens.end());

        int i = 0, j = tokens.size() - 1, s = 0;
        while (i <= j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                s++;
                i++;
                ans = max(ans, s);
            }
            else if (s > 0)
            {
                power += tokens[j];
                s--;
                j--;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};

// link : https://leetcode.com/problems/bag-of-tokens/?envType=daily-question&envId=2024-03-04