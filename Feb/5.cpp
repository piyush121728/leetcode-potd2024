#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {

        unordered_map<char, int> mp;
        int n = s.size(), index = -1;
        for (auto ch : s)
        {
            mp[ch]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] == 1)
            {
                index = i;
                break;
            }
        }

        return index;
    }
};

// link : https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05