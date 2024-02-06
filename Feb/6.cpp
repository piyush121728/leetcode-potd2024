#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<pair<string, int>> v;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            v.push_back({str, i});
        }

        sort(v.begin(), v.end());

        vector<vector<string>> ans;
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            temp.push_back(strs[v[i].second]);
            for (int j = i + 1; j < n; j++)
            {

                if (v[i].first == v[j].first)
                {
                    temp.push_back(strs[v[j].second]);
                }
                else
                {
                    i = j - 1;
                    break;
                }
                if (j == n - 1)
                {
                    i = j;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// link : https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06