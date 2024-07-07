#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int n, int exc)
    {
        int e = n;
        int cnt = e;
        while (e >= exc)
        {
            cnt += e / exc;
            e = (e / exc) + (e % exc);
        }
        return cnt;
    }
};

// link: https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2024-07-07