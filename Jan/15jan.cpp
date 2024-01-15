#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    map<int, int> totMat, totWin;

    for (auto mat : matches)
    {
        totMat[mat[0]]++;
        totMat[mat[1]]++;
        totWin[mat[0]]++;
    }

    vector<vector<int>> v(2);

    for (auto it : totMat)
    {
        if (totWin[it.first] == it.second)
        {
            v[0].push_back(it.first);
        }

        if (totWin[it.first] == it.second - 1)
        {
            v[1].push_back(it.first);
        }
    }

    return v;
}

// link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/?envType=daily-question&envId=2024-01-15