#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;

        for (auto c : s)
        {
            mp[c]++;
        }
        int odd = 0, len = 0;
        for (auto it : mp)
        {
            if (it.second % 2 == 0)
            {
                len += it.second;
            }
            else
            {
                len += it.second - 1;
                odd = 1;
            }
        }

        if (odd == 1)
        {
            len++;
        }

        return len;
    }
};

// link : https://leetcode.com/problems/longest-palindrome/?envType=daily-question&envId=2024-06-04