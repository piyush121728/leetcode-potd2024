#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<pair<char, int>> st;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')' && st.size() != 0 && st.top().first == '(')
            {
                st.pop();
            }
            else if (s[i] == '(' || s[i] == ')')
            {
                st.push({s[i], i + 1});
            }
        }
        stack<pair<char, int>> revSt;
        while (st.size() != 0)
        {
            revSt.push(st.top());
            st.pop();
        }
        string str = "";
        for (int i = 0; i < n; i++)
        {
            if (revSt.size() != 0 && revSt.top().second == i + 1)
            {
                revSt.pop();
                continue;
            }
            str += s[i];
        }

        return str;
    }
};

// link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/?envType=daily-question&envId=2024-04-06