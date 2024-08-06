#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (auto ch : word)
        {
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
            {
                break;
            }
            cnt += ((1 + (i / 8)) * freq[i]);
        }
        return cnt;
    }
};

// link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2024-08-06