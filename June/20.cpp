#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &p, int m, int minF)
    {
        int n = p.size();
        m--;
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            if (m > 0 && abs(p[i] - p[j]) >= minF)
            {
                m--;
                j = i;
            }
        }
        return m == 0;
    }
    int maxDistance(vector<int> &p, int m)
    {
        int n = p.size();
        sort(p.begin(), p.end());
        // binary search
        int l = 1, r = abs(p[0] - p[n - 1]), res = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            cout << l << " " << mid << " " << r << endl;

            if (check(p, m, mid))
            {
                l = mid + 1;
                res = max(res, mid);
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};

// link : https://leetcode.com/problems/magnetic-force-between-two-balls/?envType=daily-question&envId=2024-06-20