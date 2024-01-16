#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        if (n != m)
        {
            return false;
        }

        map<char, int> mp1, mp3;
        map<int, int> mp2;

        for (auto ch : s)
        {
            mp1[ch]++;
        }

        for (auto ch : t)
        {
            mp3[ch]++;
        }

        for (auto it : mp1)
        {
            mp2[it.second]++;
        }

        for (auto it : mp3)
        {
            if (mp1[it.first] > 0)
            {
                if (mp2[it.second] > 0)
                {
                    mp2[it.second]--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

// link : https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14
