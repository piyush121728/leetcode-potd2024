#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mp, vector<int> &nums)
    {
        map<int, vector<int>> mpp;

        for (auto x : nums)
        {
            string str = to_string(x);
            string trans = "";
            for (auto c : str)
            {
                trans += (mp[c - '0'] + '0');
            }
            int n = stoi(trans);
            mpp[n].push_back(x);
        }
        cout << endl;

        vector<int> ans;
        for (auto &[key, vec] : mpp)
        {
            for (auto x : vec)
            {
                ans.push_back(x);
            }
        }

        return ans;
    }
};

// link : https://leetcode.com/problems/sort-the-jumbled-numbers/?envType=daily-question&envId=2024-07-24