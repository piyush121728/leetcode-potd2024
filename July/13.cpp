#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &p, vector<int> &h, string d)
    {
        vector<pair<int, pair<int, char>>> v;
        map<int, int> mp;
        int n = p.size();
        for (int i = 0; i < n; i++)
        {
            mp[p[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            v.push_back({p[i], {h[i], d[i]}});
        }
        sort(v.begin(), v.end());
        stack<pair<int, pair<int, char>>> st;

        for (int i = 0; i < n; i++)
        {
            int cpos = v[i].first, cheal = v[i].second.first, cdir = v[i].second.second;
            while (!st.empty() && st.top().second.second == 'R' && cdir == 'L')
            {
                auto it = st.top();
                int pos = it.first, heal = it.second.first, dir = it.second.second;
                st.pop();
                if (cheal > heal)
                {
                    cheal--;
                }
                else if (cheal < heal)
                {
                    cheal = 0;
                    heal--;
                    st.push({pos, {heal, dir}});
                    break;
                }
                else
                {
                    cheal = 0;
                    break;
                }
            }
            if (cheal != 0)
            {
                st.push({cpos, {cheal, cdir}});
            }
        }

        vector<pair<int, int>> vec;
        while (!st.empty())
        {
            vec.push_back({mp[st.top().first], st.top().second.first});
            st.pop();
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        for (auto &[f, s] : vec)
        {
            ans.push_back(s);
        }
        return ans;
    }
};

// link : https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2024-07-13