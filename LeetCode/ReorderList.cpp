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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* headSecondHalf = reverse(slow);
        ListNode* headFirstHalf = head;

        while(headFirstHalf != nullptr && headSecondHalf != nullptr) {
            ListNode* temp = headFirstHalf->next;
            headFirstHalf->next = headSecondHalf;
            headFirstHalf = temp;

            temp = headSecondHalf->next;
            headSecondHalf->next = headFirstHalf;
            headSecondHalf = temp;
        }

        if(headFirstHalf != nullptr) {
            headFirstHalf->next = nullptr;
        }
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while(head != nullptr) {
            ListNode* n = head->next;
            head->next = prev;
            prev = head;
            head = n;
        }
        return prev;
    }
};