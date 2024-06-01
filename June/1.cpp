#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += abs(s[i] - s[i + 1]);
        }
        return sum;
    }
};

// link : https://leetcode.com/problems/score-of-a-string/?envType=daily-question&envId=2024-06-01