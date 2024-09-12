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
    ListNode* reverseEveryKElements(ListNode* head, int k) {
        if(k <= 1 || head == nullptr) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(true) {
            ListNode* lastNodeOfPreviousPart = prev;
            ListNode* lastNodeOfSublist = curr;
            ListNode* next = nullptr;

            int i = 0;
            while(curr != nullptr && i < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                i++;
            }

            if(lastNodeOfPreviousPart != nullptr) {
                lastNodeOfPreviousPart->next = prev;
            } else {
                head = prev;
            }

            lastNodeOfSublist->next = curr;

            if(curr == nullptr) {
                break;
            }

            prev = lastNodeOfSublist;
        }

        return head;
    }
};