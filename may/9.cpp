#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &h, int k)
    {
        long long res = 0;
        int i = 0;
        sort(h.begin(), h.end());
        while (k--)
        {
            if (h.back() - i > 0)
            {
                res += h.back() - i;
            }
            h.pop_back();
            i++;
        }

        return res;
    }
};
// link : https://leetcode.com/problems/maximize-happiness-of-selected-children/submissions/1251704044/?envType=daily-question&envId=2024-05-09