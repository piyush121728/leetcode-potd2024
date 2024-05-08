#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &s)
    {
        vector<string> res;
        int n = s.size();
        map<int, string> mp;
        vector<int> v = s;
        sort(s.begin(), s.end(), greater<int>());
        for (int i = 0; i < n; i++)
        {
            if (i + 1 == 1)
            {
                mp[s[i]] = "Gold Medal";
            }
            else if (i + 1 == 2)
            {
                mp[s[i]] = "Silver Medal";
            }
            else if (i + 1 == 3)
            {
                mp[s[i]] = "Bronze Medal";
            }
            else
            {
                mp[s[i]] = to_string(i + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            res.push_back(mp[v[i]]);
        }

        return res;
    }
};

//link : https: // leetcode.com/problems/relative-ranks/submissions/1252501667/?envType=daily-question&envId=2024-05-08