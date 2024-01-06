#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<vector<int>> arr;
int n;
int getNextIndex(vector<vector<int>> &arr, int l, int ele)
{
    int r = n - 1;
    int indi = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid][0] >= ele)
        {
            int indi = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return indi;
}
int rec(int i, vector<vector<int>> &arr)
{

    if (i >= n)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int notTake = rec(i + 1, arr);
    int nextIndex = getNextIndex(arr, i + 1, arr[i][1]);
    int take = rec(nextIndex, arr) + arr[i][2];

    return dp[i] = max(take, notTake);
}
int jobScheduling(vector<int> &s, vector<int> &e, vector<int> &p)
{
    n = s.size();
    dp.resize(n + 1, -1);
    arr.resize(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        arr[i] = {s[i], e[i], p[i]};
    }

    auto comp = [&](auto &vec1, auto &vec2)
    {
        return vec1[0] <= vec2[0];
    };

    sort(arr.begin(), arr.end(), comp);
    return rec(0, arr);
}

int main()
{
    return 0;
}

// link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/