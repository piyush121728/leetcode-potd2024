#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto ch : s)
        {
            mp[ch]++;
        }
        vector<pair<int, char>> v;
        for (auto it : mp)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        string str;
        for(auto x:v){
            for(int i = 0; i < x.first; i++){
                str.push_back(x.second);
            }
        }

        return str;
    }
};

// link : https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07