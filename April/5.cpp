#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string makeGood(string s)
    {
        int n = s.size();
        stack<char> st;

        for (auto x : s)
        {
            if (st.size() != 0 && abs(st.top() - x) == 32)
            {
                st.pop();
            }
            else
            {
                st.push(x);
            }
        }

        string str = "";
        while (st.size() != 0)
        {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

// link : https://leetcode.com/problems/make-the-string-great/submissions/1223608041/?envType=daily-question&envId=2024-04-05