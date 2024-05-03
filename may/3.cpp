#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string v1, string v2)
    {
        vector<string> str1, str2;
        string str = "";
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != '.')
            {
                str += v1[i];
            }
            else
            {
                int j = 0;
                while (j < str.size() - 1 && str[j] == '0')
                {
                    j++;
                }
                str1.push_back(str.substr(j));
                str = "";
            }
        }

        int j = 0;
        while (j < str.size() - 1 && str[j] == '0')
        {
            j++;
        }
        str1.push_back(str.substr(j));
        str = "";

        for (int i = 0; i < v2.size(); i++)
        {
            if (v2[i] != '.')
            {
                str += v2[i];
            }
            else
            {
                int j = 0;
                while (j < str.size() - 1 && str[j] == '0')
                {
                    j++;
                }
                str2.push_back(str.substr(j));
                str = "";
            }
        }

        j = 0;
        while (j < str.size() - 1 && str[j] == '0')
        {
            j++;
        }
        str2.push_back(str.substr(j));
        str = "";

        int n = str1.size(), m = str2.size();
        if (n < m)
        {
            while (n != m)
            {
                str1.push_back("0");
                n++;
            }
        }
        else
        {
            while (n != m)
            {
                str2.push_back("0");
                m++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int x = str1[i].size();
            int y = str2[i].size();
            if (x < y)
            {
                return -1;
            }
            else if (x > y)
            {
                return 1;
            }
            else
            {
                for (int j = 0; j < x; j++)
                {
                    if (str1[i][j] < str2[i][j])
                    {
                        return -1;
                    }
                    else if (str1[i][j] > str2[i][j])
                    {
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
};

// link : https://leetcode.com/problems/compare-version-numbers/?envType=daily-question&envId=2024-05-03