#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' && st.size() != 0 && st.top() == 'b')
            {
                cnt++;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/?envType=daily-question&envId=2024-07-30