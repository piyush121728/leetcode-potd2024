#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string res = "";
        int n = num.size();
        for (int i = 0; i < n; i++)
        {
            while (res.size() != 0 && k != 0 && res.back() > num[i])
            {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }

        while (k > 0)
        {
            res.pop_back();
            k--;
        }
        int i = 0;
        for (; i < n; i++)
        {
            if (res[i] != '0')
            {
                break;
            }
        }

        return i == res.size() ? "0" : res.substr(i);
    }
};

// link : https://leetcode.com/problems/remove-k-digits/submissions/1229071200/?envType=daily-question&envId=2024-04-11