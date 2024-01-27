#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isUnique(string s, string t)
    {
        unordered_set<char> st;
        for (auto ch : s)
        {
            if (st.count(ch) > 0)
            {
                return false;
            }
            st.insert(ch);
        }
        for (auto ch : t)
        {
            if (st.count(ch) > 0)
            {
                return false;
            }
            st.insert(ch);
        }

        return true;
    }

    int rec(int i, string str, vector<string> &arr)
    {
        if (i < 0)
        {
            return 0;
        }
        int take = 0;
        int notTake = rec(i - 1, str, arr);
        if (isUnique(str, arr[i]))
        {
            take = rec(i - 1, str + arr[i], arr) + arr[i].size();
        }
        return max(take, notTake);
    }

    int maxLength(vector<string> &arr)
    {
        int n = arr.size();

        return rec(n - 1, "", arr);
    }
};

// link : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23