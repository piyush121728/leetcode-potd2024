#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> arr = heights;
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            cnt += (arr[i] != heights[i]);
        }
        return cnt;
    }
};

// link : https://leetcode.com/problems/height-checker/submissions/1283620232/?envType=daily-question&envId=2024-06-10