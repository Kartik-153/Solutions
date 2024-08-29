#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class LinkedListCycle {
// public:
//     static ListNode* findCycleStart(ListNode* head) {
//         int cycleLength = 0;
//         ListNode* slow = head;
//         ListNode* fast = head;

//         // Find the cycle in the linked list using the two-pointer approach
//         while (fast != nullptr && fast->next != nullptr) {
//             fast = fast->next->next;
//             slow = slow->next;

//             if (slow == fast) {
//                 // Cycle found
//                 cycleLength = calculateCycleLength(slow);
//                 break;
//             }
//         }

//         return findStart(head, cycleLength);
//     }

// private:
//     static int calculateCycleLength(ListNode* slow) {
//         ListNode* current = slow;
//         int cycleLength = 0;

//         // Calculate the length of the cycle
//         do {
//             current = current->next;
//             cycleLength++;
//         } while (current != slow);

//         return cycleLength;
//     }

//     static ListNode* findStart(ListNode* head, int cycleLength) {
//         ListNode* pointer1 = head;
//         ListNode* pointer2 = head;

//         // Move pointer2 ahead by 'cycleLength' nodes
//         while (cycleLength > 0) {
//             pointer2 = pointer2->next;
//             cycleLength--;
//         }

//         // Increment both pointers until they meet at the start of the cycle
//         while (pointer1 != pointer2) {
//             pointer1 = pointer1->next;
//             pointer2 = pointer2->next;
//         }

//         return pointer1;
//     }
// };

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (!(fast && fast->next))
            return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};