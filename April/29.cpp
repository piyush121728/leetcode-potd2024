#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int tot = 0;
        for (int num : nums)
        {
            tot ^= num;
        }

        if (tot == k)
        {
            return 0;
        }

        int diff = tot ^ k;
        int op = 0;

        while (diff > 0)
        {
            op += diff & 1;
            diff >>= 1;
        }

        return op;
    }
};