#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();

        int j = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < m)
            {
                if (g[i] <= s[j])
                {
                    cnt++;
                    j++;
                    break;
                }
                j++;
            }
        }

        return cnt;
    }
};

// link : https://leetcode.com/problems/assign-cookies/description/

int main(){
    
    return 0;
}