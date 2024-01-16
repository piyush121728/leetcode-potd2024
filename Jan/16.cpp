#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    set<int> st;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (st.find(val) != st.end())
        {
            return false;
        }
        st.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (st.find(val) != st.end())
        {
            st.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return *next(st.begin(), rand() % st.size());
    }
};

int main()
{
    return 0;
}

// link : https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16