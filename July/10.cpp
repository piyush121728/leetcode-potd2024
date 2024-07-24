#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int cnt = 0;
        for (auto log : logs)
        {
            cout << log << cnt << endl;
            if (log == "../")
            {
                if (cnt != 0)
                {
                    cnt--;
                }
            }
            else if (log == "./")
            {
                cnt = cnt;
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};

// link : https://leetcode.com/problems/crawler-log-folder/?envType=daily-question&envId=2024-07-10