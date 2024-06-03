#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0, j = 0, n = s.size(), m = t.size();

        while (i < n && j < m)
        {
            j += (s[i] == t[j]);
            i++;
        }

        return m - j;
    }
};

// link : https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=daily-question&envId=2024-06-03