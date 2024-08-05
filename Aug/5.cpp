#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        int n = arr.size();
        unordered_map<string, int> mp;
        for (auto &str : arr)
        {
            mp[str]++;
        }
        int cnt = 0;
        for (auto &str : arr)
        {
            if (mp[str] == 1)
            {
                cnt++;
                if (cnt == k)
                {
                    return str;
                }
            }
        }

        return "";
    }
};

// link: https://leetcode.com/problems/kth-distinct-string-in-an-array/?envType=daily-question&envId=2024-08-05