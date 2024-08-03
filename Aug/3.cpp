#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> mp, mp1;
        for (auto x : arr)
        {
            mp[x]++;
        }
        for (auto x : target)
        {
            mp1[x]++;
        }
        for (auto &[key, val] : mp)
        {
            if (mp1[key] != val)
            {
                return false;
            }
        }
        for (auto &[key, val] : mp1)
        {
            if (mp[key] != val)
            {
                return false;
            }
        }

        return true;
    }
};

// link : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/?envType=daily-question&envId=2024-08-03