#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findRoot(string word, set<string> &st)
    {
        int n = word.size();
        string root;
        for (int l = 1; l <= n; l++)
        {
            if (st.count(word.substr(0, l)) > 0)
            {
                return word.substr(0, l);
            }
        }
        return word;
    }
    string replaceWords(vector<string> &d, string s)
    {
        set<string> st(d.begin(), d.end());
        stringstream ss(s);
        string word;
        string res;
        while (getline(ss, word, ' '))
        {
            res += findRoot(word, st) + " ";
        }
        res.pop_back();
        return res;
    }
};

// link : https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07