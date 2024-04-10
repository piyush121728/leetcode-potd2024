#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        bool skip = false;
        int i = 0;
        int j = 0;
        vector<int> res(n, 0);
        while (i < n)
        {
            if (skip == false && res[j] == 0)
            {
                skip = true;
                res[j] = deck[i];
                i++;
            }
            if (skip == true && res[j] == 0)
            {
                skip = false;
            }
            j = (j + 1) % n;
        }

        return res;
    }
};

// link : https://leetcode.com/problems/reveal-cards-in-increasing-order/?envType=daily-question&envId=2024-04-10