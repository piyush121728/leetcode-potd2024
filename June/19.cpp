#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &b, int m, int k, int mid)
    {
        int cnt = 0, n = b.size(), i = 0;

        while (i < n)
        {
            int c = 0;
            while (i < n && b[i] <= mid && c < k)
            {
                i++;
                c++;
            }
            if (c == k)
            {
                cnt++;
            }
            else
            {
                i++;
            }
        }

        return cnt >= m;
    }
    int minDays(vector<int> &b, int m, int k)
    {
        int n = b.size();

        int l = 1, r = *max_element(b.begin(), b.end());
        int mini = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(b, m, k, mid))
            {
                mini = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return mini;
    }
};

// link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/?envType=daily-question&envId=2024-06-19