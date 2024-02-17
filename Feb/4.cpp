#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        unordered_map<char,int> mp;
        for(auto ch:t){mp[ch]++;}

        vector<int> v;
        for(int i = 0; i < n; i++){
            if(mp[s[i]]>0){
                v.push_back(i);
            }
        }
    }
};
// link : https://leetcode.com/problems/minimum-window-substring/?envType=daily-question&envId=2024-02-04