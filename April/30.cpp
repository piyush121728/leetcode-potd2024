#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<long long, long long> mp;
        int n = word.size();
        long long currXor = 0;
        mp[currXor] = 1;

        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate the no. of substrings whose every characters occur even no. of times
            long long pow = (word[i] - 'a');
            currXor ^= (1 << pow);
            if (mp[currXor] > 0)
            {
                res += mp[currXor];
            }

            // calculate the no. of substrings whose only one character occurs odd no. of times
            for (char ch = 'a'; ch <= 'j'; ch++)
            {
                long long p = (ch - 'a');
                long long x_or = currXor ^ (1 << p);
                if (mp[x_or] > 0)
                {
                    res += mp[x_or];
                }
            }

            mp[currXor]++;
        }

        return res;
    }
};

// link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/?envType=daily-question&envId=2024-04-29
// Learnings : cummulative xor