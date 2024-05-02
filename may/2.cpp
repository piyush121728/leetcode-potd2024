#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_map<int, int> neg;
        for (auto x : nums)
        {
            if (x < 0)
            {
                neg[x]++;
            }
        }

        int maxi = -1;
        for (auto x : nums)
        {
            if (x > 0 && neg[-x] > 0)
            {
                maxi = max(x, maxi);
            }
        }

        return maxi;
    }
};

// link : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/?envType=daily-question&envId=2024-05-02