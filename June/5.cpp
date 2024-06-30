#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        int n = words.size();
        vector<unordered_map<char, int>> v(n);
        set<char> vis;
        for (int i = 0; i < n; i++)
        {
            for (auto ch : words[i])
            {
                v[i][ch]++;
            }
        }
        vector<string> res;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int c = 0, mini = 1e8;
            for (int i = 0; i < n; i++)
            {
                if (v[i][ch] > 0)
                {
                    c++;
                    mini = min(v[i][ch], mini);
                }
            }
            if (c == n)
            {
                for (int i = 0; i < mini; i++)
                {
                    string str = "";
                    str += ch;
                    res.push_back(str);
                }
            }
        }

        return res;
    }
};

// link : https://leetcode.com/problems/find-common-characters/submissions/1304931795/?envType=daily-question&envId=2024-06-05