#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeDifference(int n, int k, vector<int> &arr)
    {
        // code here
        int i = 0, j = k - 1;
        multiset<int> st;

        vector<int> rmin(n, INT_MAX), rmax(n, INT_MIN);
        rmin[n - 1] = rmax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rmin[i] = min(rmin[i + 1], arr[i]);
            rmax[i] = max(rmax[i + 1], arr[i]);
        }

        int res = rmax[k] - rmin[k];

        int lmax = arr[0], lmin = arr[0];

        for (int i = 1; i < n - k; i++)
        {
            int maxInRemaining = max(lmax, rmax[i + k]);
            int minInRemaining = min(lmin, rmin[i + k]);
            int currDiff = maxInRemaining - minInRemaining;
            res = min(res, currDiff);

            lmax = max(arr[i], lmax);
            lmin = min(arr[i], lmin);
        }

        res = min(res, lmax - lmin);
        return res;

        return res;
    }
};