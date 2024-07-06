#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int fullRounds = time / (n - 1);

        int extraTime = time % (n - 1);

        if (fullRounds % 2 == 0)
        {
            return extraTime + 1;
        }
        else
        {
            return n - extraTime;
        }
    }
};

// link : https://leetcode.com/problems/pass-the-pillow/submissions/1311320522/?envType=daily-question&envId=2024-07-06