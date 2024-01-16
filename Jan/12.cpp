#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        set<int> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        int v = 0, c = 0;

        int i = 0;
        for (; i < s.size() / 2; i++)
        {
            if (st.count(s[i]) > 0)
            {
                v++;
            }
            else
            {
                c++;
            }
        }
        for (; i < s.size(); i++)
        {
            if (st.count(s[i]) > 0)
            {
                v--;
            }
            else
            {
                c--;
            }
        }

        return (c == 0) && (v == 0);
    }
};

int main(){
    return 0;
}

// link : https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12