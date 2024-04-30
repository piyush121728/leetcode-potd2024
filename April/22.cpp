#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    queue<string> que;
    unordered_set<string> dead;
    void fillNeighbors(string &curr)
    {
        for (int i = 0; i < 4; i++)
        {
            char ch = curr[i];

            char dec = ch == '0' ? '9' : ch - 1;
            char inc = ch == '9' ? '0' : ch + 1;

            curr[i] = dec;
            if (!dead.count(curr))
            {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if (!dead.count(curr))
            {
                dead.insert(curr);
                que.push(curr);
            }
            curr[i] = ch;
        }
    }
    int openLock(vector<string> &deadends, string target)
    {
        for (auto x : deadends)
        {
            dead.insert(x);
        }

        string start = "0000";
        if (dead.count(start))
            return -1;

        queue<string> que;
        que.push(start);

        int level = 0;
        while (!que.empty())
        {
            int n = que.size();

            while (n--)
            {
                string curr = que.front();
                que.pop();
                if (curr == target)
                    return level;

                fillNeighbors(curr);
            }
            level++;
        }
        return -1;
    }
};

// link : https://leetcode.com/problems/open-the-lock/description/?envType=daily-question&envId=2024-04-22
