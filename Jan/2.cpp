#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int r = 0;
        for (auto num : nums)
        {
            mp[num]++;
            r = max(r, mp[num]);
        }

        vector<vector<int>> v;
        for (int i = 0; i < r; i++)
        {
            vector<int> temp;
            for (auto it : mp)
            {
                if (it.second > 0)
                {
                    temp.push_back(it.first);
                    mp[it.first]--;
                }
            }
            v.push_back(temp);
        }

        return v;
    }
};

int main(){
    return 0;
}

// link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02