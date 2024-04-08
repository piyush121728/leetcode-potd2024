#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &stud, vector<int> &sand)
    {
        stack<int> st;
        int n = stud.size();
        for (int i = n - 1; i >= 0; i--)
        {
            st.push(sand[i]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(stud[i]);
        }

        int cnt = 0;

        while (!q.empty() && cnt <= n)
        {
            if (q.front() == st.top())
            {
                q.pop();
                st.pop();
                cnt = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }

        return q.size();
    }
};

// link : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/submissions/1226655402/?envType=daily-question&envId=2024-04-08