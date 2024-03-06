#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        auto t1 = head, t2 = head->next;

        while(t1 && t2){
            if(t1==t2){
                return true;
            }
            t1 = t1->next;
            if(!t2->next){
                return false;
            }
            t2 = t2->next->next;
        }

        return false;
    }
};

// link : https://leetcode.com/problems/linked-list-cycle/?envType=daily-question&envId=2024-03-06