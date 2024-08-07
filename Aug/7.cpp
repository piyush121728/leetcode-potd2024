#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string helper(string subs)
    {
        string res = "";
        int n = subs.size();
        vector<vector<string>> mp{
            {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
            {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"},
            {"Twenty"},
            {"Thirty"},
            {"Forty"},
            {"Fifty"},
            {"Sixty"},
            {"Seventy"},
            {"Eighty"},
            {"Ninety"}};

        if (n > 2 && subs[2] != '0')
        {
            res = mp[0][subs[2] - '0' - 1] + " Hundred";
        }

        if (n > 1)
        {
            string part = "";
            part += subs[1];
            part += subs[0];
            int num = stoi(part);
            if (num >= 10 && num <= 20)
            {
                if (res.size())
                {
                    res += " ";
                }
                res += mp[1][num - 10];
                return res;
            }
        }

        if (n > 1 && subs[1] != '0')
        {
            if (res.size())
            {
                res += " ";
            }
            res += mp[subs[1] - '0'][0];
        }

        if (n > 0 && subs[0] != '0')
        {
            if (res.size())
            {
                res += " ";
            }
            res += mp[0][subs[0] - '0' - 1];
        }

        return res;
    }
    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }
        vector<string> v{"Hundred", "Thousand", "Million", "Billion"};
        string str = to_string(num);
        int i = str.size() - 1;
        vector<string> ans;
        int cnt = 0;
        while (i >= 0)
        {
            int j = 0;
            string subs = "";
            string res = "";
            while (i >= 0 && j < 3)
            {
                subs += str[i];
                i--;
                j++;
            }
            string t = helper(subs);
            if (t.size() != 0)
            {
                res += t;
                if (cnt > 0)
                {
                    res += " " + v[cnt];
                }
            }
            ans.push_back(res);
            cnt++;
        }
        string finalRes = "";
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (ans[i].size() == 0)
            {
                continue;
            }
            if (i == ans.size() - 1)
            {
                finalRes += ans[i];
            }
            else
            {

                finalRes += " " + ans[i];
            }
        }

        return finalRes;
    }
};

// link : https://leetcode.com/problems/integer-to-english-words/?envType=daily-question&envId=2024-08-07