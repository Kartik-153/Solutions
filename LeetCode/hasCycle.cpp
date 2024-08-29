#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head != NULL) {
        if(s.find(head) != s.end()) {
            return false;
        }
        s.insert(head);
        head = head->next;
        }
        return true;
    }

    // Given the head of a LinkedList with a cycle, find the length of the cycle.
    int hasCycle2(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                return calculateCycleLength(slow);
            }
        }
    }

private:
    int calculateCycleLength(ListNode* slow) {
        ListNode* curr = slow;
        int len = 0;

        while(true) {
            curr = curr->next;
            len+=1;
            if(curr==slow) 
                break;
        }
        return len;
    }
};