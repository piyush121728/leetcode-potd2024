#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();

        int j = n - 1;
        while (j >= 0 && s[j] == ' ')
        {
            j--;
        }
        int cnt = 0;
        while (j >= 0 && s[j] != ' ')
        {
            cnt++;
            j--;
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01