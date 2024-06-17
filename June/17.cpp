#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
    }
};

// link : https://leetcode.com/problems/sum-of-square-numbers/submissions/1291380746/?envType=daily-question&envId=2024-06-17