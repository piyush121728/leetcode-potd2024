#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int len = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < len; i++)
        {
            mp[nums[i]]++;
        }

        int cnt = 0;

        for (auto it : mp)
        {

            while (it.second > 0)
            {
                if (it.second % 3 == 0)
                {
                    cnt += it.second / 3;
                    it.second = 0;
                }
                else
                {
                    it.second -= 2;
                    if (it.second < 0)
                    {
                        return -1;
                    }
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main(){
    return 0;
}

// link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04