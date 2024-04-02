#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        unordered_map<char, char> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] == 0)
            {
                mp[s[i]] = t[i];
            }
            if (mp[s[i]] != t[i])
            {
                return false;
            }
        }

        unordered_map<char, char> mp1;
        for (int i = 0; i < n; i++)
        {
            if (mp1[t[i]] == 0)
            {
                mp1[t[i]] = s[i];
            }
            if (mp1[t[i]] != s[i])
            {
                return false;
            }
        }

        return true;
    }
};

// link : https://leetcode.com/problems/isomorphic-strings/?envType=daily-question&envId=2024-04-02