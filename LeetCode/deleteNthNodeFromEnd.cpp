#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int length = count(head);
		int pos = length - n + 1;
		head = deleteNodeAtPosition(head, pos);
		return head;
	}

	int count(ListNode *head) {
		int x = 0;
		while(head != NULL) {
			x += 1;
			head = head->next;
		}
		return x;
	}

	ListNode* deleteNodeAtPosition(ListNode* head, int pos) {
    if (head == NULL) {
        return NULL;
    }
    
    if (pos == 1) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
    
    ListNode* prev = head;
    ListNode* curr = head->next;
    for (int i = 2; i < pos && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr != NULL) {
        prev->next = curr->next;
        delete curr;
    }
    
    return head;
}
};
