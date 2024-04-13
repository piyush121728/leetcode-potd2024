#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leftSmaller(int n, vector<int> &v)
    {
        // code here
        vector<int> nsl(n, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            while (st.size() != 0 && st.top().first >= v[i])
            {
                st.pop();
            }
            if (st.size() != 0)
            {
                nsl[i] = st.top().second;
            }
            else
            {
                nsl[i] = -1;
            }

            st.push({v[i], i});
        }
        return nsl;
    }

    vector<int> rightSmaller(int n, vector<int> &v)
    {
        vector<int> nsr(n, 0);
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() != 0 && st.top().first >= v[i])
            {
                st.pop();
            }
            if (st.size() != 0)
            {
                nsr[i] = st.top().second;
            }
            else
            {
                nsr[i] = n;
            }

            st.push({v[i], i});
        }
        return nsr;
    }

    int maximalRectangle(vector<vector<char>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int maxArea = 0;

        vector<int> h(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == '0')
                {
                    h[j] = 0;
                }
                else
                {
                    h[j]++;
                }
            }

            vector<int> nsl = leftSmaller(n, h);
            vector<int> nsr = rightSmaller(n, h);

            for (int k = 0; k < n; k++)
            {
                int w = nsr[k] - nsl[k] - 1;
                maxArea = max(maxArea, w * h[k]);
            }
        }

        return maxArea;
    }
};

// link : https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2024-04-13