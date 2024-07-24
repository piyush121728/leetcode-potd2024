#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;

        int i = 0, n = s.size();
        string ans = "";
        while (i < n)
        {

            if (s[i] == ')')
            {
                string str = "";
                while (st.size() != 0 && st.top() != '(')
                {
                    str += st.top();
                    st.pop();
                }
                st.pop();
                for (int k = 0; k < str.size(); k++)
                {
                    st.push(str[k]);
                }
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2024-07-11