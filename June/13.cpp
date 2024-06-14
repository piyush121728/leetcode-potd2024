#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int> &s, vector<int> &st)
    {
        sort(s.begin(), s.end());
        sort(st.begin(), st.end());
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            res += abs(s[i] - st[i]);
        }

        return res;
    }
};

// link : https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13