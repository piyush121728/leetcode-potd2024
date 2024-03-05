#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            if (s[i] == s[j])
            {
                while (i < j)
                {
                    if (s[i] == s[i + 1])
                    {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }

                while (i < j)
                {
                    if (s[j] == s[j - 1])
                    {
                        j--;
                    }
                    else
                    {
                        break;
                    }
                }
                i++;
                j--;
            }
            else
            {
                break;
            }
        }

        if (i > j)
        {
            return 0;
        }

        return j - i + 1;
    }
};

// link : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/submissions/1194946061/?envType=daily-question&envId=2024-03-05