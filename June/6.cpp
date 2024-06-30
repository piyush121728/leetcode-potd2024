#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> mp;
        for (auto n : hand)
        {
            mp[n]++;
        }

        for (auto it : mp)
        {
            if (it.second > 0)
            {
                for (int i = it.first + 1; i < it.first + groupSize; i++)
                {
                    if (mp[i] < it.second)
                    {
                        return false;
                    }
                    mp[i] -= it.second;
                }
            }
        }

        return true;
    }
};

// link : https://leetcode.com/problems/hand-of-straights/?envType=daily-question&envId=2024-06-06