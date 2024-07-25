#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, string> op1(string s, int x)
    {
        string st;
        int cnt = 0;
        for (auto c : s)
        {
            if (st.size() != 0 && c == 'b' && st.back() == 'a')
            {
                st.pop_back();
                cnt += x;
            }
            else
            {
                st.push_back(c);
            }
        }
        return {cnt, st};
    }
    pair<int, string> op2(string s, int y)
    {
        string st;
        int cnt = 0;
        for (auto c : s)
        {
            if (st.size() != 0 && c == 'a' && st.back() == 'b')
            {
                st.pop_back();
                cnt += y;
            }
            else
            {
                st.push_back(c);
            }
        }
        return {cnt, st};
    }
    int maximumGain(string s, int x, int y)
    {
        int n = s.size(), res = 0;

        if (x > y)
        {
            auto it = op1(s, x);
            res += it.first;
            res += op2(it.second, y).first;
        }
        else
        {
            auto it = op2(s, y);
            res += it.first;
            res += op1(it.second, x).first;
        }
        return res;
    }
};
// link : https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2024-07-12