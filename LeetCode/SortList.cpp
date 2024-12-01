#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) 
            return head;
        
        ListNode* second = split(head);
        head = sortList(head);
        second = sortList(second);

        return merge(head, second);
    }

private:
    ListNode* split(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if(fast != nullptr) {
                slow = slow->next;
            }
        }

        ListNode* temp = slow->next;
        slow->next = nullptr;
        return temp;
    }

    ListNode* merge(ListNode* first, ListNode* second) {
        if(first == nullptr) return second;
        if(second == nullptr) return first;

        if(first->val < second->val) {
            first->next = merge(first->next, second);
            return first;
        } else {
            second->next = merge(first, second->next);
            return second;
        }
    }
};