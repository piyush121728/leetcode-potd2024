#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nsl(n, 0), nsr(n, 0); // Next smaller left(nsl), next smaller right(nsr)
        stack<pair<int, int>> mis;        // {ele,index} monotonic increasing misack(mis)

        for (int i = 0; i < n; i++)
        {
            while (!mis.empty() && arr[i] <= mis.top().first)
            {
                mis.pop();
            }
            if (mis.empty())
            {
                nsl[i] = -1;
            }
            else
            {
                nsl[i] = mis.top().second;
            }
            mis.push({arr[i], i});
        }

        while (!mis.empty())
        {
            mis.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!mis.empty() && arr[i] < mis.top().first)
            {
                mis.pop();
            }
            if (mis.empty())
            {
                nsr[i] = n;
            }
            else
            {
                nsr[i] = mis.top().second;
            }
            mis.push({arr[i], i});
        }

        long long res = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            long long l = i - nsl[i], r = nsr[i] - i;
            long long totSubarray = l * r;
            long long totMinSum = totSubarray * arr[i];
            res = (res + totMinSum) % mod;
        }

        return res;
    }
};

// link : https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20