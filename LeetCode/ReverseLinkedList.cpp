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
    // ListNode* reverseList(ListNode* head) { // Iterative approach
    //     ListNode* prev = NULL;
    //     ListNode* next = NULL;
    //     ListNode* curr = head;
    //     while(curr != NULL) {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     head = prev;
    //     return head;
    // }
    ListNode* reverseList(ListNode* head) { // Recursive approach
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};
