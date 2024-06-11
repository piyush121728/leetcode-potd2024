#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        set<int> st(arr2.begin(), arr2.end());
        unordered_map<int, int> mp;
        vector<int> temp;
        for (auto x : arr1)
        {
            if (st.count(x) == 0)
            {
                temp.push_back(x);
            }
            else
            {
                mp[x]++;
            }
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for (auto x : arr2)
        {
            for (int i = 0; i < mp[x]; i++)
            {
                ans.push_back(x);
            }
        }
        for (auto x : temp)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

// link : https://leetcode.com/problems/relative-sort-array/?envType=daily-question&envId=2024-06-11