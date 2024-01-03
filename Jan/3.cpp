#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int n = bank.size();
        int m = bank[0].size();
        vector<int> v;

        for (auto str : bank)
        {
            int cnt = 0;
            for (auto ch : str)
            {
                cnt += (ch == '1');
            }

            if (cnt > 0)
            {
                v.push_back(cnt);
            }
        }

        if (v.size() == 0)
        {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {

            ans += v[i] * v[i + 1];
        }

        return ans;
    }
};

int main()
{
    return 0;
}

// link :https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03