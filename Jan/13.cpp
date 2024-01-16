#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> mp1;
        for (auto ch : s)
        {
            mp1[ch]++;
        }

        int cnt = 0;
        for (auto ch : t)
        {
            if (mp1[ch] > 0)
            {
                mp1[ch]--;
            }
            else
            {
                cnt++;
            }
        }

        return cnt;
    }
};

int main(){
    return 0;
}

// link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/