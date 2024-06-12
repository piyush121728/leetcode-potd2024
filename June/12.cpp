#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, mid = 0, h = n - 1;

        while (mid <= h)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[l]);
                l++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[h]);
                h--;
            }
        }

        for (auto &x : nums)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

// link : https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2024-06-12