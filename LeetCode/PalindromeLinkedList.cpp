#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        for(int i = 0; i <= n / 2 && n != 0; i++) {
            if(nums[i] != nums[n - i- 1]) {
                flag = true;
                break;
            }
        }
        return !flag;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }

        return check(v);
    }
};
