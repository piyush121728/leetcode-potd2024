#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        sort(s.begin(), s.end(), greater<char>());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                swap(s[i], s[s.size() - 1]);
                break;
            }
        }
        return s;
    }
};

// link : https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01