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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;

    ListNode* result = new ListNode();

    while(l1 != NULL || l2 != NULL) {
        int sum = carry;
        if(l1 != NULL) {
            sum+=l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum+=l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        Insert_at_end(result, sum % 10);
    }
    if(carry > 0) {
        Insert_at_end(result, carry);
    }
    return result->next;
    }
    int count(struct ListNode *p) {
    int c = 0;
    while(p!=NULL) {
        c+=1;
        p=p->next;
    }
    return c;
    }
    void Insert_at_end(struct ListNode* p, int v) {
        int x = count(p);
        ListNode* t = new ListNode();
        for(int i = 0; i < x - 1; i++) {
            p = p->next;
        }
        t->val = v;
        t->next = p->next;
        p->next = t;
    }
};

int main() {

    return 0;
}