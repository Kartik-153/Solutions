#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Move the pointers to the right place
        for (int i = 1; curr != nullptr && i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        // `prev` now points to the node before the left position
        // `curr` now points to the `left` position

        ListNode* lastNodeOfFirstPart = prev;
        ListNode* lastNodeOfSubList = curr;
        ListNode* next = nullptr;

        // Reverse the sublist from left to right
        for (int i = 0; curr != nullptr && i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the previous part with the reversed sublist
        if (lastNodeOfFirstPart != nullptr) {
            lastNodeOfFirstPart->next = prev;
        } else {
            head = prev;
        }

        // Connect the reversed sublist with the next part
        lastNodeOfSubList->next = curr;

        return head;
    }
};

