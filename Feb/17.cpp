#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &h, int b, int l)
    {
        int n = h.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0;
        long long sum = 0;
        for (; i < n - 1; i++)
        {
            if (h[i] < h[i + 1])
            {
                minHeap.push(abs(h[i] - h[i + 1]));
                if (minHeap.size() > l)
                {
                    sum += minHeap.top();
                    minHeap.pop();
                    if (sum > b)
                    {
                        return i;
                    }
                }
            }
        }

        return i;
    }
};

// link : https://leetcode.com/problems/furthest-building-you-can-reach/?envType=daily-question&envId=2024-02-17