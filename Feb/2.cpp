#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> v;
        queue<string> q;
        for (int i = 1; i <= 9; i++)
        {
            q.push(to_string(i));
        }

        while (q.size() != 0)
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string str = q.front();
                q.pop();

                if (str[str.size() - 1] == '9')
                {
                    continue;
                }
                str.push_back(str[str.size() - 1] + 1);
                int num = stoi(str);
                if (num >= low && num <= high)
                {
                    v.push_back(num);
                }
                q.push(str);
                if (num > high)
                {
                    break;
                }
            }
        }
        return v;
    }
};

// link : https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02